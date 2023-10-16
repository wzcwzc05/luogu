import socket
import urllib


def extract_ip():
    hostname = socket.gethostname()
    addrs = socket.getaddrinfo(hostname, None)
    ip_address = []
    for (family, socktype, proto, canonname, sockaddr) in addrs:
        ip_address.append(sockaddr)
    return ip_address


user_name = "12345678"  # 自己的账号
user_password = "12345"  # 自己的密码
ISP = "@zgyd"  # 中国移动
# ISP=""     #校园网
# ISP="@zglt"  #中国联通
# ISP="@zgdx"    #中国电信

ip_address = []
for ip in extract_ip():
    if ip[0].find("10."):
        ip_address.append(ip)

str1 = "http://10.9.1.3:801/eportal/?c=Portal&a=login&callback=dr1003&login_method=1&user_account=,0,"
str2 = "&user_password="
str3 = "&wlan_user_ip="
str4 = "&wlan_user_ipv6=&wlan_user_mac=000000000000&wlan_ac_ip=&wlan_ac_name=&jsVersion=3.3.3"
print(ip_address)
for ip in ip_address:
    print(ip)
    get_request = str1 + user_name + ISP + str2 + \
        user_password + str3 + ip + str4
    print(get_request)
    urllib.request.urlopen(get_request)
    
