#coding:utf-8
import urllib
import urllib2


def postData(kind, tmp_search):
    values = {}
    values['strSearchType'] = kind
    values[' historyCount'] = '1'
    values['strText'] = tmp_search
    values['doctype'] = "ALL"
    values['match_flag'] = "forward"
    values['displaypg'] = '20'
    values['sort'] = "CATA_DATE"
    values['orderby'] = "desc"
    values['showmode'] = "list"
    values['dept'] = "ALL"
    values['x'] = '20'
    values['y'] = '22'

    data = urllib.urlencode(values)
    count = 0
    url = "http://www.libopac.seu.edu.cn:8080/opac/openlink.php"
    get_url = url + "?" + data
    request = urllib2.Request(get_url)
    response = urllib2.urlopen(request)
    count = count + 1
    print(count)

if __name__ == '__main__':
    kind = "title"
    search_data = ['唐', '一', '鹏', '你', '是', '个', '好', '人']
    tmp_search = search_data[7]
    print(tmp_search)
    postData(kind, tmp_search)
