#-*-utf-8-*-
import urllib
import urllib2
import string
import re


def getList():
    url = "http://www.libopac.seu.edu.cn:8080/opac/ajax_topten.php"
    request = urllib2.Request(url)
    response = urllib2.urlopen(request)
    topTenData = response.read()

    topTenList = re.findall("\'((&#\w{5};){1,})\'", topTenData)
    for i in range(0, len(topTenList)):
        topTenList[i] = topTenList[i][0]
        topTenList[i] = topTenList[i].replace('&#x', '\u')
        #print(topTenList[i])
        topTenList[i] = topTenList[i].replace(';', '')
        #print(topTenList[i].decode('unicode-escape'))
    return topTenList

if __name__ == '__main__':
	print(getList()[0].decode('unicode-escape'))
