TOOD: remove

- add missing types as dummies
- add empty `interfaces` sdk
- sort template classes below their template types
- detect indirect dependency cycles

TOOD:

- rename template arguments to use fully qualified names
- add includes for template arguments (add decompose_type() and use that in many places?)

# Source2Gen

Source2Gen is a tool to generate Source 2 SDKs. \
This project aims to provide an easy way to generate SDKs for various Source 2 games. \
An example of such SDKs could be found at [source2sdk](https://github.com/neverlosecc/source2sdk/tree/cs2).

---

## Usage

### Windows

TODO: how to run on windows? we need the user to set `PATH`. Hint: Perhaps we
can use the registry to find the game path and set `PATH` automatically.

```sh
source2gen
copy .\sdk-dummy\source2gen_user_types.hpp .\sdk
# view generated sdk
dir .\sdk
```

### Linux

```sh
./scripts/run.sh "$HOME/.steam/steam/steamapps/cs2/"
pc ./sdk-dummy/source2gen_user_types.hpp ./sdk
# view generated sdk
ls ./sdk
```

You can also invoke source2gen directly , e.g. for debugging, by running

```sh
LD_LIBRARY_PATH=$HOME/.steam/steam/steamapps/cs2/game/bin/linuxsteamrt64/:$HOME/.steam/steam/steamapps/cs2/game/csgo/bin/linuxsteamrt64/ \
  source2gen
```

Source2Gen for Linux support is currently in an alpha state. There will be
errors, bugs, and wrong output. Please only file issues if you want to work on
them. This note will be removed once we have thoroughly tested Source2Gen on
Linux.

### Using the generated SDK

The sdk depends on a file/module called "source2gen_user_types". This file has
to be provided by the user and expose all types listed in
[source2gen_user_types.hpp](sdk-dummy/source2gen_user_types.hpp). If you don't
intend to access any of these types, you can use the dummy
[source2gen_user_types.hpp](sdk-dummy/source2gen_user_types.hpp).

## Getting Started

These instructions will help you set up the project on your local machine for development and testing purposes.

### Prerequisites

#### Windows

- Visual Studio 2019 or newer
- premake5

#### Linux

- g++-13 or newer
- CMake

### Clone the repository

To clone the repository with submodules, run the following command:

```bash
git clone --recurse-submodules https://github.com/neverlosecc/source2gen.git
```

### Update the Game Definition

Before building the project in Visual Studio, you will need to update the game definition.
The default definition is `CS2`. \
Possible options are: `CS2`, `SBOX`, `ARTIFACT2`, `ARTIFACT1`, `DOTA2`, `UNDERLORDS`, `DESKJOB`.

or

You can use premake5 options and specify which game you want to dump:

```bash
 --game=CS2
 Choose a particular game for dumping source 2 sdk; one of:
     ARTIFACT1        Artifact Classic
     ARTIFACT2        Artifact Foundry
     CS2              Counter-Strike 2
     DESKJOB          Aperture Desk Job
     DOTA2            Dota 2
     HL_ALYX          Half-Life: Alyx
     SBOX             S&BOX
     THE_LAB_ROBOT_REPAIR Portal: Aperture Robot Repair
     UNDERLORDS       Dota Underlords
```

or

When using CMake, you can set `cmake -DSOURCE2GEN_GAME=CS2`

### Building the project

#### With premake5

- Open a command prompt or terminal in the project's root directory.
- Run the following command to generate the Visual Studio solution:

```bash
premake5 vs2019 --game=CS2
```

- Open the generated source2gen.sln file in Visual Studio.
- Build the solution in the desired configuration (Debug, Release, or Dist).

#### With CMake

- Open a command prompt or terminal in the project's root directory.
- Run the following sequence of commands to build the project:

```bash
cmake -B build -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -DSOURCE2GEN_GAME=CS2
cmake --build build
```

---

## Credits

This project is made possible by the contributions of various individuals and projects. Special thanks to the following:

- **[es3n1n](https://github.com/es3n1n)** - source2gen [contributor](https://github.com/neverlosecc/source2gen/commits?author=es3n1n)
- **[cpz](https://github.com/cpz)** - source2gen [contributor](https://github.com/neverlosecc/source2gen/commits?author=cpz)
- **[Cre3per](https://github.com/Cre3per/)** - source2gen [contributor](https://github.com/neverlosecc/source2gen/commits?author=cre3per), Linux support
- **[Soufiw](https://github.com/Soufiw)** - source2gen [contributor](https://github.com/neverlosecc/source2gen/commits?author=Soufiw)
- **[anarh1st47](https://github.com/anarh1st47)** - source2gen [contributor](https://github.com/neverlosecc/source2gen/commits?author=anarh1st47)
- **[praydog](https://github.com/praydog)** - the author of the original [Source2Gen](https://github.com/praydog/Source2Gen) project

This project also utilizes the following open-source libraries:

- **[Premake](https://github.com/premake/premake-core)** - Build configuration tool
- **[CMake](https://github.com/Kitware/CMake)** - Build tool

If you've contributed to the project and would like to be listed here, please submit a [pull request](https://github.com/neverlosecc/source2gen/pulls) with your information added to the credits.
