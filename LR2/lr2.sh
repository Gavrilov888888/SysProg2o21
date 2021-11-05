@@ -0,0 +1,9 @@
#!/bin/bash
echo Input the pattern:
read pattern
echo Input the dir:
read dir
if find $dir -maxdepth 1 -type f -name "$pattern"
then
find $dir -maxdepth 1 -type f -name "$pattern">lab2.txt
fi