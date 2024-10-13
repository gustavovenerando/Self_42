#! /usr/bin/bash

id -G FT_USER | tr ' ' ',' | tr -d '\n'
