# Pipex_42


## 1. Project description

The goal of the project is to simulate the behavior of a shell command pipeline, similar to the pipe (|) in Unix-like systems. 

The execution of the pipex program should do the same as the following command:

```ruby
$> < file1 comand1 | comand2 > file2

# Example

$> < infile.txt grep hola | wc -l > outfile.txt
```

The programme shall be executed as follows:

```ruby
$> ./pipex file1 comand1 comand2 file2

# Example

$> ./pipex infile.txt "grep hola" "wc -l" outfile.txt
```

## 2. Mandatory part

- The infile must exist, and also have the necessary permissions to be read.

- The outfile does not have to exist, if it does, the result will be overwritten, deleting the previous content.
  
- Commands must exist. We are going to check if one of the paths of the PATH variable of the environment has this command inside (the executable corresponding to the command).

- It is not necessary for the commands to act on the infile, you can run the command _ls_.


## 3. How to execute the program

- Clone the repository

- Execute the comand make inside the project folder

```ruby
$> make
```

- Execute the program with the desired arguments as follow

```ruby
$> ./pipex infile.txt "grep hola" "grep hello" outfile.txt
```

## 4. Bonus Part

### 4.1. Multiple pipes

It manages more than two pipes. Following the structure: 

```ruby
$> ./pipex archivo1 comand1 comand2 comand3 ... archivo2

# Example

$> ./pipex infile.txt "grep hola" "grep hello" "wc -l" outfile.txt
```

In terms of infile, outfile and commands everything remains unchanged. Only more than two commands can be executed.

### 4.2. Here_doc

When the first parameter is ‘here_doc’, the program is expected to handle the operators << (to redirect multiple lines of text as input from the terminal) and >> (to redirect or append output to a file). In this case, the terminal acts as the input file (infile). The syntax for executing this case is:

```ruby
$> ./pipex here\_doc LIMITER comand1 comand2 outfile

# Example

$> ./pipex here\_doc EOF "grep hello" "wc -l" outfile.txt
```

- When you run it, it allows the user to type into the terminal whatever he wants to enter as an infile in the program. Once the limator is typed in a row followed by a line break, the program will run with the previously typed content.

- The outfile does not have to exist, if it does, the result will be added in a new line. The result is not overwritten by deleting the previous content, but added afterwards.

- 🚨 These program only works correctly with two commands, not with several 🚨

### 4.3. Execute bonus part

Just run the command make bonus. The new program is overwritten on top of the one generated by the mandatory part, as they have the same name.

```ruby
$> make bonus
```
