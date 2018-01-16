#!/usr/bin/python3

import re
import os
import sys
import shutil
import subprocess

A = sys.argv[1]
C = sys.argv[2]
P = sys.argv[3]
F = sys.argv[4]

print("""
<html>
  <head>
    <link href="styles/main.css" rel="stylesheet" type="text/css"/>
  </head>
  <body>
    <center>
      <h1>Forum</h1>
      <a href="proxy.php?F=public/main.php">Back to menu</a>
      <table>
        <tr>
          <td>
            <h3>Add a new comment</h3>
            <form action="./proxy.php" method="get">
              <table>
                <tr>
                  <td>Comment:</td>
                  <td><input type='text' name='C'/></td>
                </tr>
              </table>
              <input type='hidden' name='F' value='public/forum.php'/>
              <input type='hidden' name='A' value='append'/>
              <input class="btn" type='submit' value='add'/>
            </form>
          </td>
          <td>
            <h3>Upload an image <i>(tar.gz</i>)</h3>
            <form action="./proxy.php?F=public/forum.php&A=upload"
                  method="post" enctype="multipart/form-data">
              <table>
                <tr>
                  <td>image:</td>
                  <td><input type="file" name="F" size="50"/></td>
                </tr>
              </table>
              <input class="btn" type='submit' value='upload'/>
            </form>
          </td>
          <td>
            <h3>Search in comments</h3>
            <form action="./proxy.php" method="get">
              <table>
                <tr>
                  <td>Pattern:</td>
                  <td><input type='text' name='P'/></td>
                </tr>
              </table>
              <input type='hidden' name='F' value='public/forum.php'/>
              <input type='hidden' name='A' value='search'/>
              <input class="btn" type='submit' value='search'/>
            </form>
          </td>
        <tr>
      <table>
      <br/>
      """)
pattern = re.compile(".*")
if A == "append":
  fout = open("forum/msg/" + str(len(os.listdir("forum/msg")) + 1), 'w')
  fout.write(C)
  fout.close()
  print("<div class=\"msg\">Comment added!</div>")
elif A == "upload":
  shutil.copyfile(F, "work/ar.tar.gz")
  os.chdir("work")
  s = subprocess.Popen(["/bin/tar", "zxvf", "ar.tar.gz"],
      stderr=subprocess.STDOUT, stdout=subprocess.PIPE).communicate()[0]
  v = subprocess.Popen(["rm", "ar.tar.gz"],
      stderr=subprocess.STDOUT, stdout=subprocess.PIPE).communicate()[0]
  s = s.rstrip()
  s = s.decode()
  k = s.rfind("\n")
  if k != -1:
    s = s[k + 1:]
  os.chdir("..")
  fname = "forum/img/" + str(len(os.listdir("forum/img")) + 1)
  fout = open(fname, 'w')
  fout.write("<img src='" + "work/" + s + "'/>")
  fout.close()
  print("<div class=\"msg\">Image added!</div>")
elif A == "search":
  pattern = re.compile(P)
print("<table>")
for file in sorted(os.listdir("forum/msg"), key=lambda y: int(y)):
  fin = open("./forum/msg/" + file, 'r')
  fmsg = fin.read()
  fin.close()
  if not pattern.match(fmsg) is None:
    print("<tr><td>Message ", file, ":</td><td>", fmsg, "</td></tr>")
print("</table>")
for file in sorted(os.listdir("forum/img"), key=lambda y: int(y)):
  fin = open("./forum/img/" + file, 'r')
  fimg = fin.read()
  fin.close()
  if not (pattern.match(fimg) is None):
    print("<tr><td>", fimg, "</td></tr>")
print("""
    </center>
  </body>
</html>
      """)
