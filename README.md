# :no_entry_sign: UnsafePlusPlus
![alt-text](https://github.com/n0nexist/UnsafePlusPlus/blob/main/image.png?raw=true)<br>
<b>Avoid using <i>unsafe</i> functions in your C/C++ code.</b>

# :nut_and_bolt: Compiling
```
$ g++ main.cpp -o unsafeplusplus
```

# :computer: Usage
```
$ ./unsafeplusplus (file or directory)
```

# :small_red_triangle: Rating scale
<ul>
<li><b>LOW</b> - <i>the author has to be an idiot to use this function in a vulnerable way.</i></li>
<li><b>MID</b> - <i>if the input passed to this function isn't checked, it's probably vulnerable.</i></li>
<li><b>HIGH</b> - <i>the author is an idiot for using this function, and it's 100% vulnerable.</i></li>
</ul>

# How does it work :interrobang:
<i>
This program checks for unsafe functions on every line of a given file (or directory), with it's extension being either .c or .cpp<br> 
It does not check how the functions are actually used, hence it just gives the function's rating.
</i>
