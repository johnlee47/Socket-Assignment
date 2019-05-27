#include "Socket.cpp"
int main(int argc , char *argv[])
{
tcp_client c;
string host;

cout<<"Enter hostname to get data : ";
cin>>host;

//connect to host
c.conn(host , 80);

//send some data
c.send_data("GET / HTTP/1.1\r\n\r\n");

//receive and echo reply
cout<<"----------------------------\n\n";
cout<<c.receive(1024);
cout<<"\n\n----------------------------\n\n";

//done
return 0;
}