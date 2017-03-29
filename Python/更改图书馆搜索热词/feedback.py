#coding:utf-8
import getList
import postData

search_data = [u'唐', u'一', u'鹏', u'是', u'gay']
kind = "title"
topTenList = getList.getList()

print topTenList[1].decode('unicode-escape') == search_data[0]
for i in range(0, len(topTenList)):
    print(topTenList[i].decode('unicode-escape'))
