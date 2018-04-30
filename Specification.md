# Specification（规范）
这东西其实是写给我自己看的，因为我有强迫症。  
大概就是一些提交代码的规则吧。  

## File Naming ##
* 每个*问题*单独为一个文件，命名为 `$problem_number.cpp` ，其中 `$problem_number` 为问题编号，如 `1001` 。  
* 每个*算法实现*单独为一个文件，命名为 `$algorithm_name.cpp` ，其中 `$algorithm_name` 为算法名称，如 `Insertion_Sort` ，若算法名称中含有空格，则使用下划线 `_` 代替。
* *未解决*的*问题*与*算法实现*放入 `/` 内，如 `/1468.cpp` `/Insertion_Sort.cpp` 。
* *已解决*的*问题*放入 `/resolved/$oj_name/` 内，其中 `$oj_name` 为使用的 OJ 名称，如 `luogu` ， OJ 名称中只能包含小写字母。
* *已解决*的*算法实现*放入 `/resolved/algorithm_implementations/` 内。

## Commiting ##
* 每次*提交*可以提交多个*问题*或*算法* ，但同时只能提交一种，如*未解决*的*算法*、*已解决*的*问题*……
* 提交*未解决*的*问题*时，提交信息为 `unresolved problems $time` ，其中 `$time` 为一个*时间范围*，代表在何时还未解决。
* 提交*已解决*的*问题*时，提交信息为 `resolved problems $time` ，其中 `$time` 为一个*时间范围*，代表在何时解决的。
* 提交*未解决*的*算法*时，提交信息为 `unimplemented algorithms $time` ，其中 `$time` 为一个*时间范围*，代表在何时还未解决。
* 提交*已解决*的*算法*时，提交信息为 `implemented algorithms $time` ，其中 `$time` 为一个*时间范围*，代表在何时解决的。
* *时间范围*为一个日期或在一个日期之前，如 `on 2018-04-30` 或 `before 2018-04-29` ，年份占四位，月份和日期各占两位，其中用横线 `-` 分隔，先后顺序必须为年月日。
* 其它提交如更新 `README.md` 时，提交信息可以随意，一次提交可有多个不同文件，但尽量保持一致性，如 `updates readme` `adds specification` `just readme and gitignore` ，尽量不要含有缩写，并且所有字母都为小写。
