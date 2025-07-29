# NativeUI
<p align="center">
<img src="icon.svg" height="150" alt="NativeUI icon">

Wip oop based ui framework written in cpp with raylib and cpp-bindings. Using [this very awesome cpp template](https://github.com/CapsCollective/raylib-cpp-starter)
</p>

## Getting Started

### Installing Dependencies

Before building the project, you will need to install all relevant dependencies for your platform so that the project has access to all the tools required, and raylib can compile and link correctly. You can find intructions for installing dependencies on macOS, Linux, and Windows in the [docs file on installing dependencies](docs/InstallingDependencies.md).

### Building the Project
Once you have cloned this repository and installed dependencies, building the project is as simple as running these two commands in its root directory:

#### macOS & Linux
```console
$ make setup
$ make
```

#### Windows
```console
> mingw32-make setup
> mingw32-make
```

The first command will clone in the lastest C++ bindings and targeted version of raylib, copy across any relevant header files into `/includes`, and build a static library file from them, placing it in `/lib`. The second command then compiles, runs and cleans up your project.

### Draw.io
You can also take a look at `./ui.drawio`, representing class diagram.

### Doxygen
You can take a look at documentation generation with doxygen [on this page](docs/Doxygen.md)

## Licence

This project is licenced under an unmodified zlib/libpng licence, which is an OSI-certified, BSD-like licence that allows static linking with closed source software. Check [`LICENCE`](LICENCE) for further details.
