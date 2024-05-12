# markdown_fmt

## What this program does

### ex00
**input00**

```
| header1 | header2 |
| ------- | --- |
| 1  | 2          |
| 3     | 4 |
```
**output00**

```
| header1 | header2 |
| ------- | ------- |
| 1       | 2       |
| 3       | 4       |
```
## ex01
**input01**

```
| header1 | header2 |
|------ | --- |
| 1  |          |
| 3     | 4 |
```

**output01**

```
| header1 | header2 |
| ------- | ------- |
| 1       |         |
| 3       | 4       |
```

## ex02
**input02**

```
|             artist name|    url|
| --- | ------ |
|Tame Impala                  | https://tameimpala.com/        |
|     cocteau twins|  https://cocteautwins.com        |
|Fishmans|                               http://www.fishmans.jp/                             |
```
**output01**

```
| artist name   | url                      |
| ------------- | ------------------------ |
| Tame Impala   | https://tameimpala.com/  |
| cocteau twins | https://cocteautwins.com |
| Fishmans      | http://www.fishmans.jp/  |
```

## Rule
- Common to all rows
    - One space between `|` and value at left end of cell
- Header and body rows
    - Values are left-aligned.
    - Spaces in values are kept as they are.
- Delimiter rows
    - One space between `|` and the value at both ends of the cell
    - At least three `|`s should be connected.

## How to build
generate exec file
```
make
```

exec it
```
./markdown_fmt
```

delete object files
```
make clean
```

delete object files and exec file
```
make fclean
```

fclean and re-compile
```
make re
```

