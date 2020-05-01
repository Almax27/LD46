@echo off

echo Setting P4 environment variables...

p4 set P4CONFIG=.p4config
p4 set P4IGNORE=$home/.p4ignore;.gitignore;.p4ignore

echo Done, Please restart P4V for changes to take effect

PAUSE

