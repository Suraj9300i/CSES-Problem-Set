Competitive Programming Setup on macOS with Sublime Text

Table of Contents

	1.	Introduction
	2.	Sublime Text Setup for C++
	3.	GCC Compiler Installation
	4.	Setting GCC as Default on macOS
	5.	Git Workflow for Competitive Programming
	6.	Build System for C++
	7.	Sample .gitignore

1. Introduction

This repository contains C++ code for competitive programming. The guide includes:

	•	Installing and configuring the GCC compiler on macOS.
	•	Sublime Text setup for efficient C++ development.
	•	Git configuration with a .gitignore file for proper version control.
 
2. Sublime Text Setup for C++

Installing Sublime Text

	1.	Download and install Sublime Text from the official website.
	2.	Install the “Package Control” manager via Tools > Install Package Control.

Creating a Build System for C++

	1.	Go to Tools > Build System > New Build System.
	2.	Paste the following code:

 `
   {
   "cmd": ["bash", "-c", "g++ -std=c++14 -Wno-unused-variable '${file}' -o '${file_path}/${file_base_name}' && '${file_path}/${file_base_name}'"],
   "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
   "working_dir": "${file_path}",
   "selector": "source.c, source.c++",
   "variants": [
      {
         "name": "Run",
         "cmd": ["bash", "-c", "g++ -std=c++14 -Wno-unused-variable '${file}' -o '${file_path}/${file_base_name}' && '${file_path}/${file_base_name}'"]
      }
   ]
}
 `


 3.	Save it as cpp_competitive.sublime-build.
	4.	To use it, go to Tools > Build System > cpp_competitive.

Layout Customization (3-Column with Max 2 Columns)

To adjust Sublime Text to a 3-column layout with 2 groups of columns:

	1.	Navigate to View > Layout > Columns: 3.
	2.	Arrange your files into two columns by dragging tabs across the layout.

3. GCC Compiler Installation

Installing GCC on macOS

To use GCC instead of Clang on macOS, follow these steps:

	1.	Install Homebrew: Run this command in the terminal to install Homebrew (if you haven’t installed it yet):
`
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
`

  
