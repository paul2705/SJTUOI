from os import system
import os
import requests
from bs4 import BeautifulSoup
import time
import sys

if len(sys.argv)>1 and sys.argv[1]=="push":
    system("git add *.c *.h README.md && git commit -m \"e2 submission\" && git push")
    exit(0)

cookies = {
    'JSESSIONID': 'dummy',
    'save': '1',
    'sid': 'ca0dbff17f39339748db0c8196c1b89bf67abf03bf3fcced4d46e1d507973a5e'
}

zipPath = './a.tar'
Makefile='''test:
	gcc *.c -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic
'''

with open("Makefile","w") as f:
    f.write(Makefile)
system("tar -cf a.tar *.c *.h Makefile")
os.remove("Makefile")

s = requests.Session()
s.cookies.update(cookies)

def getProblemStatus(sess, url):
    soup = None
    while True:
        html = sess.get(url).text
        soup = BeautifulSoup(html, features="lxml")
        status = soup.select(
            "#status > div.section__header > h1 > span:nth-child(2)"
        )[0].get_text().strip()
        if status not in ["Waiting", "Compiling", "Fetched", "Running"]:
            break
        else:
            time.sleep(1)
    if(status!="Accepted"):
        warning = soup.select(
            "#status > div.section__body > pre"
        )[0].get_text().strip()
        print("!!"+status+"!!")
        return warning
    return status

files = {
    'code': ('code.tar', open(zipPath, 'rb'), 'application/tar'),
}
postUrl = f'https://joj.sjtu.edu.cn/d/vg151_fall_2021_manuel/homework/6187c0b9c5c40500079a4c9a/6187b702c5c40500079a4c41/submit'
html = s.get(postUrl).text
soup = BeautifulSoup(html, features="lxml")
csrfToken = soup.select(
    "#panel > div.main > div > div.medium-9.columns > div:nth-child(2) > div.section__body > form > div:nth-child(3) > div > input[type=hidden]:nth-child(1)"
)[0].get('value')
response = s.post(
    postUrl,
    files=files,
    data={
        'csrf_token': csrfToken,
        'lang': 'make'
    },
)
print(getProblemStatus(s,response.url))
os.remove("a.tar")
