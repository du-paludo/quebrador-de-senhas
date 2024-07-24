# Password Cracking Project

This project demonstrates different methods of password cracking, including brute force and backtracking with pruning. It consists of multiple C source files that implement and test these algorithms.

## Files

1.  `main.c`: Contains the main function to run the password cracking tests.
2.  `quebrador-senha.c`: Implements the password cracking algorithms.
3.  `biblioteca.c`: Provides utility functions and the environment for testing the algorithms.
4.  `biblioteca.h`: Header file for `biblioteca.c`.
5.  `quebrador-senha.h`: Header file for `quebrador-senha.c`.

## Algorithms

### Brute Force Method

This method tries every possible combination of characters to find the password.

`int exaustivo(char senha[], int indice);`

### Backtracking with Pruning

This method uses backtracking and avoids reusing characters to improve efficiency.

`int poda(char aux[], char senha[], int indice, int letras, int numeros);`

## Running the Project

### Prerequisites

-   A C compiler (e.g., `gcc`);
-   A file named `senhas.txt` containing passwords to be cracked.

### Compilation

Compile the project using `make`.

### Execution

Run the compiled program:

`./quebra-senha`

## How the Code Works

### main.c

-   Loads the passwords from `senhas.txt`.
-   Runs the password cracking tests using both brute force and backtracking with pruning methods.
-   Compares the performance and efficiency of the two methods.

### quebrador-senha.c

-   Implements the brute force and backtracking with pruning algorithms.
-   Provides functions to test each password cracking method.

### biblioteca.c

-   Contains utility functions for handling passwords, measuring time, and counting login attempts.
-   Provides the `login` function to simulate password verification.


## Functions

`exaustivo(char senha[], int indice)`

Attempts to find the password using brute force.

`poda(char aux[], char senha[], int indice, int letras, int numeros)`

Attempts to find the password using backtracking with pruning.

`quebrador_senha_exaustivo()`

Initializes the brute force password cracking process.

`quebrador_senha_poda()`

Initializes the backtracking with pruning password cracking process.

`carregar_senhas(char *nome_arquivo)`

Loads passwords from a specified file.

`login(char *senha)`

Simulates the password verification process.

`inicia_tempo()`

Starts the timer.

`finaliza_tempo()`

Stops the timer.

`tempo_decorrido()`

Returns the elapsed time in seconds.

`zera_contadores()`

Resets the login attempt counter.

`total_login()`

Returns the total number of login attempts.

`proxima_senha()`

Advances to the next password in the list.

## Output

The program outputs the results of the password cracking tests, including the number of login attempts and the time taken for each method. It also compares the efficiency of the two methods.
