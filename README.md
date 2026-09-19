*This project has been created as part of the 42 curriculum by abegou, aldecour.*

# Description

## What is a shell ?
>An operating system shell is a computer program that provides relatively broad and direct access to the system on which it runs. The term shell refers to how it is a relatively thin layer around an operating system.

(quote from [https://en.wikipedia.org/wiki/Shell_(computing)])\
Minishell is a project about, you guessed it, making a small(er) shell.

## What can *Petit Fossile* do ?
Our minishell includes a lot of basic shell features, such as :\
- Display a prompt to get user input.
- Builtins commands implementation[^2].
- Search for and lauches the requested executable.
- Expand variables with `'` and `"` rules.
- Redirects command i/o with `<`, `>`, `<<` and `>>`.
- Allows for piping command i/o.
- Basic signal handling for ctrl + C, ctrl + D and ctrl + \\.
- And some super-secret stuff no one will ever find.... :t-rex:

[^2]: All builtins are: echo with option -n, cd, pwd, export, unset, env and exit.

# Instructions

Afer pulling the repository, simply run `make` to compile the project and enter `./minishell` to launch our prehistoric shell !:shell:\
You can then enjoy the wonders of using our perfect shell daily for all of your shelling (?) needs !

# Resources

[Git cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)
