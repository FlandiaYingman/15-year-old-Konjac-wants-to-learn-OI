//P1022 计算器的改良

#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

double solve(const string equation, char var);
vector<double> getConstCoefficient(const string expression, char var);
vector<double> getVarCoefficient(const string expression, char var);
void replaceAll(string& str, string origin, string replacement);
vector<string> splitString(const string s, char delim);
double sumDoubles(vector<double> d);
char first(string str);

int main() {
    string input;
    cin >> input;
    char var = first(input);
    cout << var << "=";
    printf("%.3f", solve(input, var));

    return 0;
}

double solve(const string equation, char var) {
    vector<string> v = splitString(equation, '=');

    string left = v[0];
    string right = v[1];

    double leftConst = sumDoubles(getConstCoefficient(left, var));
    double rightConst = sumDoubles(getConstCoefficient(right, var));
    double leftVar = sumDoubles(getVarCoefficient(left, var));
    double rightVar = sumDoubles(getVarCoefficient(right, var));

    double leftVarSum = leftVar + -rightVar;
    double rightConstSum = -leftConst + rightConst;

    double ans = rightConstSum / leftVarSum;

    if (ans == -0) {
        return -ans;
    }

    return ans;
}

vector<double> getConstCoefficient(const string expression, char var) {
    string tempExp;
    tempExp.assign(expression);
    replaceAll(tempExp, "-", "+-");
    vector<string> coefficients = splitString(tempExp, '+');
    vector<double> result;


    for (string coe : coefficients) {
        if (coe == "") {
            continue;
        }
        if (coe.find(var) == string::npos) {
            replaceAll(coe, "+", "");
            result.push_back(stod(coe));
        }
    }

    return result;
}

vector<double> getVarCoefficient(const string expression, char var) {
    string tempExp;
    tempExp.assign(expression);
    replaceAll(tempExp, "-", "+-");
    vector<string> coefficients = splitString(tempExp, '+');
    vector<double> result;

    for (string coe : coefficients) {
        size_t pos;
        if (coe == string(1, var)) {
            result.push_back(1);
            continue;
        }
        if (coe == "-" + string(1, var)) {
            result.push_back(-1);
            continue;
        }
        if ((pos = coe.find(var)) != string::npos) {
            coe.replace(pos, 1, "");
            replaceAll(coe, "+", "");
            result.push_back(stod(coe));
        }
    }

    return result;
}

void replaceAll(string& str, string origin, string replacement) {
    string tmp;
    tmp.assign(str);
    std::size_t pos = 0;
    while (true) {
        pos = tmp.find(origin, pos);
        if (pos == string::npos) {
            break;
        }
        tmp.replace(pos, origin.length(), replacement);
        pos += replacement.length();
    }
    str.assign(tmp);
}

vector<string> splitString(const string s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

double sumDoubles(vector<double> d) {
    double sum = 0;
    for (double doub : d) {
        sum += doub;
    }
    return sum;
}

char first(string str) {
    for (int i = 0; i < str.length(); i++)
        if (islower(str[i]))
            return str[i];
    return 0;
}