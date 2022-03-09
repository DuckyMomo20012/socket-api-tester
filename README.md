# A simple CPP template.

> ⚠️ WARNING: This template is unstable, use with caution.

<table>
  <tr>
    <th>Language</th>
    <td>C++17</td>
  </tr>
  <tr>
    <th>OS</th>
    <td>Debian 11</td>
  </tr>
</table>

## How to build:

```bash
make
```

## Cleanup build:

```bash
make clean
```

[Makefile template ref:](https://makefiletutorial.com/#makefile-cookbook)

## Program

Your linux should have installed these packages:

- gcc
- gdb

## Debug

Ref: [C and Cpp Debugging in VS Code](https://github.com/bloominstituteoftechnology/CS-Wiki/wiki/C-and-Cpp-Debugging-in-VS-Code)

<details>
<summary>launch.json</summary>

```json
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "name": "g++ - Build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/19127631",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        },
        {
          "description": "Set Disassembly Flavor to Intel",
          "text": "-gdb-set disassembly-flavor intel",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "C/C++: g++ build active file",
      "miDebuggerPath": "/usr/bin/gdb"
    }
  ]
}
```

</details>

<details>
<summary>tasks.json</summary>

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build",
      "command": "gcc",
      "args": ["-Wall", "helloWorld.c", "-o", "helloWorld"],
      "problemMatcher": {
        "owner": "cpp",
        "fileLocation": ["relative", "${workspaceFolder}"],
        "pattern": {
          "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
          "file": 1,
          "line": 2,
          "column": 3,
          "severity": 4,
          "message": 5
        }
      }
    }
  ]
}
```

</details>
