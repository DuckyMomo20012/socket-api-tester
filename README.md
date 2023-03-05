<div align="center">

  <h1>A simple HTTP client using socket</h1>

  <p>
    Simulate GET request using socket
  </p>

<!-- Badges -->
<p>
  <a href="https://github.com/DuckyMomo20012/socket-api-tester/graphs/contributors">
    <img src="https://img.shields.io/github/contributors/DuckyMomo20012/socket-api-tester" alt="contributors" />
  </a>
  <a href="">
    <img src="https://img.shields.io/github/last-commit/DuckyMomo20012/socket-api-tester" alt="last update" />
  </a>
  <a href="https://github.com/DuckyMomo20012/socket-api-tester/network/members">
    <img src="https://img.shields.io/github/forks/DuckyMomo20012/socket-api-tester" alt="forks" />
  </a>
  <a href="https://github.com/DuckyMomo20012/socket-api-tester/stargazers">
    <img src="https://img.shields.io/github/stars/DuckyMomo20012/socket-api-tester" alt="stars" />
  </a>
  <a href="https://github.com/DuckyMomo20012/socket-api-tester/issues/">
    <img src="https://img.shields.io/github/issues/DuckyMomo20012/socket-api-tester" alt="open issues" />
  </a>
  <a href="https://github.com/DuckyMomo20012/socket-api-tester/blob/main/LICENSE">
    <img src="https://img.shields.io/github/license/DuckyMomo20012/socket-api-tester.svg" alt="license" />
  </a>
</p>

<h4>
    <a href="https://github.com/DuckyMomo20012/socket-api-tester/">View Demo</a>
  <span> · </span>
    <a href="https://github.com/DuckyMomo20012/socket-api-tester">Documentation</a>
  <span> · </span>
    <a href="https://github.com/DuckyMomo20012/socket-api-tester/issues/">Report Bug</a>
  <span> · </span>
    <a href="https://github.com/DuckyMomo20012/socket-api-tester/issues/">Request Feature</a>
  </h4>
</div>

<br />

<!-- Table of Contents -->

# :notebook_with_decorative_cover: Table of Contents

- [About the Project](#star2-about-the-project)
  - [Features](#dart-features)
- [Getting Started](#toolbox-getting-started)
  - [Prerequisites](#bangbang-prerequisites)
  - [Run Locally](#running-run-locally)
- [Usage](#eyes-usage)
  - [Compile](#computer-compile)
  - [Sending requests](#incoming_envelope-sending-requests)
  - [Cleanup files](#sponge-cleanup-files)
- [Debugging](#mag-debugging)
- [Roadmap](#compass-roadmap)
- [Contributing](#wave-contributing)
  - [Code of Conduct](#scroll-code-of-conduct)
- [FAQ](#grey_question-faq)
- [License](#warning-license)
- [Contact](#handshake-contact)
- [Acknowledgements](#gem-acknowledgements)

<!-- About the Project -->

## :star2: About the Project

<!-- Features -->

### :dart: Features

- This program will send an **ONLY HTTP** request to the server and receive a
  response.
- Response data is extracted to an output file (text file is recommended).
- Logging:

  - Response header is saved to `log/header.txt`.
  - Request history is saved to `log/request.txt`.

- Currently, this program only has `GET` request mode.

<!-- Getting Started -->

## :toolbox: Getting Started

<!-- Prerequisites -->

### :bangbang: Prerequisites

This project requires the following prerequisites:

- Operating system: `Linux` and `macOS`.

  > **Note**: This app only supports `Linux` and `macOS`. Currently not
  > supporting `Windows`.

- GCC, G++: `>= 10.2.1`.
- GDB.
- make.

Install GCC, G++, GDB, and make:

```bash
sudo apt update
sudo apt install build-essential
```

<!-- Run Locally -->

### :running: Run Locally

Clone the project:

```bash
git clone https://github.com/DuckyMomo20012/socket-api-tester.git
```

Go to the project directory:

```bash
cd socket-api-tester
```

Build program:

```bash
make
```

Run program:

```bash
./dist/main "http://www.example.com" "out.txt"
```

<!-- Usage -->

## :eyes: Usage

### :computer: Compile

`Makefile` is provided for compiling. You can use `make` command to compile.

Targets:

- `all`: Compile all `*.cpp` files in `src` folder.

  - Description:

    - Compile all `*.cpp` files in `src` folder to `build` folder.

    - `*.cpp` files in `src` folder will be compiled to `*.o` and `*.d` files in
      `build` folder.

    - The final executable file named `main` will be placed in `dist` folder.

  - Usage:

    ```bash
    make all
    ```

- `clean`: Remove all compiled files:

  - Description:

    - Remove all files in `build` and `dist` folder.

  - Usage:

    ```bash
    make clean
    ```

### :incoming_envelope: Sending requests

- File `main`: Sending `GET` request to a website and save response to a file.

  - Description:

    - Program will send a `GET` request to a website, accept both
      `Content-Length` response and `chunked` response.

    - Responses format in your output file depends on response type:

      - **Content-Length:** Entire body data.
      - **chunked:** Length of current chunk in hexadecimal format + Chunk data.

    - Program will create a `log` folder containing two files:

      - `header.txt`: Log response header
      - `request.txt`: Log request history.

      > Socket will automatically timeout after **3.0 seconds** without any
      > responses. You can change this in file `main.cpp`. E.g:
      >
      > ```C
      > double timeout_sec = 3.0;
      > ```

  - Usage:

    ```bash
    ./main <http website> <output file>
    ```

    Arguments:

    - `http website`: URL of **HTTP** website to send request. Support both
      `Content-Length` response or `chunked` response E.g:
      `http://www.example.com`, `http://info.cern.ch`.

    - `output file`: File to write response. A text file is recommended. E.g:
      `out.txt`, `out.md`.

### :sponge: Cleanup files

- This command will delete `build` folder and compiled `main` program.

  ```bash
  make clean
  ```

<!-- Debugging -->

## :mag: Debugging

Read more:
[C and Cpp Debugging in VS Code](https://github.com/bloominstituteoftechnology/CS-Wiki/wiki/C-and-Cpp-Debugging-in-VS-Code)

<!-- Roadmap -->

## :compass: Roadmap

- [ ] Optimize header detection part.

<!-- Contributing -->

## :wave: Contributing

<a href="https://github.com/DuckyMomo20012/socket-api-tester/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=DuckyMomo20012/socket-api-tester" />
</a>

Contributions are always welcome!

<!-- Code of Conduct -->

### :scroll: Code of Conduct

Please read the
[Code of Conduct](https://github.com/DuckyMomo20012/socket-api-tester/blob/main/CODE_OF_CONDUCT.md).

<!-- FAQ -->

## :grey_question: FAQ

- Is this project still maintained?

  - No, but I will only update documentation.

- Are you planning to support Windows OS in the future?

  - No, we are not adding support for Windows any time soon (and most likely
    never).

<!-- License -->

## :warning: License

Distributed under MIT license. See
[LICENSE](https://github.com/DuckyMomo20012/socket-api-tester/blob/main/LICENSE)
for more information.

<!-- Contact -->

## :handshake: Contact

Duong Vinh - [@duckymomo20012](https://twitter.com/duckymomo20012) -
tienvinh.duong4@gmail.com

Project Link:
[https://github.com/DuckyMomo20012/socket-api-tester](https://github.com/DuckyMomo20012/socket-api-tester).

<!-- Acknowledgments -->

## :gem: Acknowledgements

Here are useful resources and libraries that we have used in our projects:

- [Awesome Readme Template](https://github.com/Louis3797/awesome-readme-template):
  A detailed template to bootstrap your README file quickly.
