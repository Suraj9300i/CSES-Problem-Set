Competitive Programming Setup on macOS with Sublime Text

 ```
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
 ```


Save it as cpp_competitive.sublime-build.
To use it, go to Tools > Build System > cpp_competitive.
