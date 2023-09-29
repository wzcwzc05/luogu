import socket
import urllib
import urllib.request
import json

def extract_ip():  # 获取本机ip地址
    hostname = socket.gethostname()
    addrs = socket.getaddrinfo(hostname, None)
    ip_address = []
    for (family, socktype, proto, canonname, sockaddr) in addrs:
        ip_address.append(sockaddr)
    return ip_address


user_name = "2362405068"  # 自己的账号
user_password = "Unstarlight8192"  # 自己的密码
ISP = "@zgyd"  # 中国移动
# ISP=""     #校园网
# ISP = "@cucc"  # 中国联通
# ISP="@ctc"    #中国电信

ip_address = []
for ip in extract_ip():
    if ip[0][0:3] == "10.":
        ip_address.append(ip[0])

str1 = "http://10.9.1.3:801/eportal/?c=Portal&a=login&callback=dr1003&login_method=1&user_account=%2C0%2C"
str1_b = "http://10.9.1.4:801/eportal/?c=Portal&a=login&callback=dr1003&login_method=1&user_account=%2C0%2C"
str2 = "&user_password="
str3 = "&wlan_user_ip="
str4 = "&wlan_user_ipv6=&wlan_user_mac=000000000000&wlan_ac_ip=&wlan_ac_name=&jsVersion=3.3.3"
print(ip_address)
for ip in ip_address:
    get_request = str1 + user_name + ISP + str2 + \
        user_password + str3 + ip + str4
    get_request_backup = str1_b + user_name + ISP + str2 + \
        user_password + str3 + ip + str4
    print('Testing ', ip)
    print(get_request)
    try:
        response = urllib.request.urlopen(get_request)
    except urllib.error.URLError as e:
        try:
            response = urllib.request.urlopen(get_request_backup)
        except urllib.error.URLError as e:
            print("网络连接失败！")
    str_resp = response.read().decode('utf-8')
    str_json = str_resp[7:len(str_resp)-1]
    data = json.loads(str_json)  # 返回值解析为json数据
    if (data['result'] == "1" and data['msg'] == "\u8ba4\u8bc1\u6210\u529f"):
        print("认证成功！")
    elif (data['ret_code'] == 1 and data['msg'] == "QXV0aGVudGljYXRpb24gZmFpbA=="):
        print("运营商错误！")
    elif (data['ret_code'] == 1 and data['msg'] == "bGRhcCBhdXRoIGVycm9y"):
        print("密码错误！")
    elif (data['ret_code'] == 2):
        print("已经登录！")
    elif (data['ret_code'] == 1 and data['msg'] == "dXNlcmlkIGVycm9yMQ=="):
        print("用户名错误！")
    #print(data)
