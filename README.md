# A simple HTTP client using socket

Simulate GET request using socket

## Environment:

CPP version: `c++17`

<table>
  <tr>
    <th>OS</th>
    <th>gcc, g++</th>
    <th>Tested</th>
  </tr>
  <tr>
    <td>Debian 11</td>
    <td>10.2.1</td>
    <td>Passed ✔</td>
  </tr>
  <tr>
    <td>Ubuntu 22.04</td>
    <td>11.2.0</td>
    <td>Passed ✔</td>
  </tr>
</table>

## Description:

This program will send an ONLY HTTP request to the server and receive a response.
Response data is extracted to an output file (text file is recommended) and the header
is saved to `log/header.txt`.

Currently, this program only has GET request mode.

## How to build:

This will compile a program that is targeted in [Makefile](https://github.com/DuckyMomo20012/socket-api-tester/blob/master/Makefile#L7).

```bash
make
```

## Cleanup build:

This command will delete .build folder and compiled program.

```bash
make clean
```

[Makefile template link](https://makefiletutorial.com/#makefile-cookbook)

## Program Requirements:

Your Linux environment should have installed these packages:

- GCC, G++
- GDB

## Run program:

- After the build, you will see an executable file name "main". You can change this
  in Makefile, variable `TARGET`.

- This program requires two arguments:

  - `http website`: URL of **HTTP** website to send request (with a trailing
    slash '/' ). Support both `Content-Length` response or `chunked` response E.g:
    http://www.example.com/, http://info.cern.ch/.

  - `output file`: File to write response. Recommend a text file (.txt). E.g:
    out.txt, out.json.

- Run executable:

```bash
./main http://www.example.com/ out.txt
```

OR

```bash
./main "http://www.example.com/" "out.txt"
```

- Types of responses in your output file:

  - **Content-Length:** Entire body data.
  - **chunked:** Length of current chunk in hexadecimal format + Chunk data.

- Program will create a log folder containing two files:
  - `header.txt`: Log response header
  - `request.txt`: Log request history.

> Socket will automatically timeout after 3.0 seconds without any responses. You
> can change this in file `main.cpp`.

## Debug:

Read more: [C and Cpp Debugging in VS Code](https://github.com/bloominstituteoftechnology/CS-Wiki/wiki/C-and-Cpp-Debugging-in-VS-Code)

## TODO:

- [ ] Optimize header detection part.
