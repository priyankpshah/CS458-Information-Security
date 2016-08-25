#include <openssl/ssl.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  int bytes;
  char buf[1024];


  if (argc != 3) {
    printf("./exec hostname port");
    return -1;
  }

  char* hostname = argv[1];
  int port = atoi(argv[2]);

  // init the ssl lib
  SSL_library_init();
  printf("client...1\n");

  //SSL_METHOD* method;
  SSL_CTX *ctx;
  OpenSSL_add_all_algorithms();
  SSL_load_error_strings();

  const SSL_METHOD* method = SSLv3_client_method();
  ctx = SSL_CTX_new(method);

  // create a standard tcp client
  int server;
  struct hostent* host;
  struct sockaddr_in addr;
  printf("client...2\n");

  host = gethostbyname(hostname);
  server = socket(PF_INET, SOCK_STREAM, 0);
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = *(long*)(host->h_addr);
  printf("client...3\n");

  connect(server, (struct sockaddr*)&addr, sizeof(addr));
  printf("client...4\n");

  SSL* ssl;
  ssl = SSL_new(ctx);
  SSL_set_fd(ssl, server);

  printf("client...5\n");
  int sv = SSL_connect(ssl);
  printf("client...6\n");
  printf("sv = %d\n", sv);
  if (sv != 1) {
    printf("Can't establish ssl connection with server...\n");
    // send a string to
    SSL_free(ssl);
    return -1;
  }
int receive=0;
char num[1024];
      while(1) {
	
	printf("\nEnter any number: "); // number input from user
	scanf("%s", num);
	
	SSL_write(ssl,num,strlen(num)); // sending data to server

	int exp = atoi(num);
	exp=exp+1;			//for verification of server response
	 	
	
	int receive = SSL_read(ssl, buf, sizeof(buf));	//retrive data from server
	
	if(receive>0)			//display server response
	{	
	printf("\n Server Response: %s",buf);
	}

	int ver = atoi(buf);		//server response in 'ver'
	if(exp==ver)			//verify server data
	{
	printf("\n valid response from server:: \n");
	}
	else
	{
	printf("\nresponse is not valid!!!:: \n");
	}
  
  }

  SSL_free(ssl);
}
