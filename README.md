*This project has been created as part of the 42 curriculum by abegou, aldecour.*

# Description

## What is a shell ?
>An operating system shell is a computer program that provides relatively broad and direct access to the system on which it runs. The term shell refers to how it is a relatively thin layer around an operating system.
(quote from [wikipedia shell's page](https://en.wikipedia.org/wiki/Shell_(computing)))\

Minishell is a project about, you guessed it, making a small(er) shell, based on GNU's bash.

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

Afer pulling the repository, simply run `make` to compile the project and enter `./minishell` to launch our prehistoric shell ! :shell:\
You can then enjoy the wonders of using our perfect shell daily for all of your shelling (?) needs !

# Resources

Here are all the ressources used during the development :\
[Git cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)\
[Koor C ressources](https://koor.fr/C/Index.wp)\
[Guide about processes](https://www.cs.tufts.edu/cs/21/notes/processes/processes_c.html)\
[Explanation and usage of signals](https://www.codequoi.com/en/sending-and-intercepting-a-signal-in-c/)\
[Wink's video about linux sys calls](https://www.youtube.com/watch?v=Odezvr0skO8)\
[CodeVault's entire channel](https://www.youtube.com/watch?v=Odezvr0skO8), such a mine of information.\
[A wonderful piece of documentation](https://github.com/MarKowPowLow/documentation_minishell_FSI) from a student at our school. Thanks a lot !\
[Wikipedia's page about /dev/random](https://en.wikipedia.org/wiki//dev/random), which helped a lot for generating a random file name for our heredoc handling.\
[GNU bash reference manual](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html)\
And of course, [God's gift to mankind](https://man7.org/linux/man-pages/man1/man.1.html).
