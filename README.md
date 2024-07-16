
# Simple example for nlohmann json

## Overview

This project demonstrates the use of the [nlohmann/json](https://github.com/nlohmann/json) library for JSON manipulation in C++. The project includes several functions to create, serialize, deserialize, and interact with JSON data.

The functions used in this project are sourced from this Gist by lyandut:\
https://gist.github.com/lyandut/98d4eb75add96fafdc06c6f94c9317fe

I have added only the project structure and build files to facilitate a quick start.

## Directory Structure

```files
workspace/
├── main.cpp
├── README.md
└── single_include/
    └── nlohmann/
        └── json.hpp
```

## Getting Started

### Prerequisites

Make sure you have the following software installed:

- [CMake](https://cmake.org/) 3.10 or higher
- A C++ compiler supporting C++17 (e.g., g++ 7.4.0 or higher)

```console
$ sudo apt install cmake
```

### Building the Project

1. **Clone the repository:**

    ```console
    $ git clone https://github.com/null-galaxy/nlohmann-json-simple-example.git &&\
      cd nlohmann-json-simple-example
    ```

2. **(optional) Replace current file json.h more actual downloaded from official repo**

Download using curl:\
Use the curl command with the specific URL of the file you want to download

Latest Release
```console
$ curl -O -L https://github.com/nlohmann/json/releases/latest/download/json.hpp
```

Specific Release (v3.11.3)
```console
$ curl -O -L https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp
```

Used flags
- `-O`: Save the downloaded file with the same name as the remote file.
- `-L`: Follow redirects if the URL points to a different location.


Verification (Specific Release):
Once the download completes, verify that the file json.hpp has been downloaded to your current directory.


3. **Create a `build` directory and navigate to it:**

    ```console
    $ mkdir build &&\
      cd build
    ```

4. **Generate build files using CMake:**

    ```console
    cmake ..
    ```

5. **Build the project:**

    ```console
    $ make
    ```

6. **Run the executable:**

    ```bash
    $ ./main
    ```

### Project Files

- `main.cpp`: The main program file that includes the main function and calls various JSON manipulation functions.
- `single_include/nlohmann/json.hpp`: Header file for the nlohmann JSON library.

## Functions Overview

The project includes the following functions:

- `void create_first_json()`: Creates a simple JSON object.
- `void create_explicit_cases()`: Creates more complex JSON objects with explicit cases.
- `nlohmann::json deserialize()`: Deserializes a JSON string to a JSON object.
- `void serialize(const nlohmann::json &j)`: Serializes a JSON object to a string.
- `void diff_serialization_and_assignment()`: Demonstrates the difference between serialization and assignment.
- `void interact_with_iostream()`: Interacts with JSON data using standard I/O streams.
- `void interact_with_fstream()`: Interacts with JSON data using file streams.
- `void interact_with_iterator()`: Demonstrates JSON data interaction using iterators.
- `void arbitrary_type_convert()`: Converts arbitrary types to JSON and vice versa.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [nlohmann/json](https://github.com/nlohmann/json) - JSON for Modern C++
- [Original Functions Source - Gist by lyandut](https://gist.github.com/lyandut/98d4eb75add96fafdc06c6f94c9317fe)

## Contributing

If you would like to contribute to this project, please fork the repository and submit a pull request. For major changes, please open an issue first to discuss what you would like to change.

## Contact

If you have any questions, feel free to open an issue or contact the repository owner at [voiduin@gmail.com](mailto:voiduin@gmail.com).
