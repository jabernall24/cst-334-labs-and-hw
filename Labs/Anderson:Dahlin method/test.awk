#!/usr/bin/awk -f

/R/ {
    read++;
}
/W/ {
    write++;
}

END {
    print read, write;
}