# JajaGit
Tiny version control system with native Git smart HTTP client.
License: GNU GPLv3

JajaGit is standalone, not tied to JajaOS/JajaLang.
Compatible with standard Git object format.
Supports fetch/clone/pull, pack delta apply, loose objects, refs, index.

## Commands
- jajagit init          Create empty repository
- jajagit add <file>    Stage file to index
- jajagit commit -m msg Create commit from index
- jajagit log           Show commit history
- jajagit ls            List tree of HEAD
- jajagit checkout <id> Switch working tree
- jajagit clone <url>   Clone remote repository
- jajagit pull          Fetch and merge remote
- jajagit help          Print help

## Build
gcc jajagit.c -o jajagit -Wall -lz -lcrypto -lssl
