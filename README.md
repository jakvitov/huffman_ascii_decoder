# About project
This is a Huffman decoder and you can use it to decode files, that contain ASCII characters and are compressed using the Huffman code.
## Installation

Use the included bash makefile

```bash
chmod +x makefile.sh && ./makefile.sh
```

## Usage
Insert the absolute path to the file that is compressed using the Huffman code:
```bash
Wellcome to the Huffman ASCII decoder!
----------------------------------------
Insert the name of the file that you would like to decode:
/home/me/compressedfiles/file1.huf
```
If you use relative path, the software might not work properly.
After you successfully enter the file name, it will be translated shortly.
```bash
Insert the name of the result file:
translation.txt
Translating...
**************
Completed!
**************
```


## License
[MIT](https://choosealicense.com/licenses/mit/)
