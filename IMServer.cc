#include"IMServer.hpp"
using namespace std;

int main()
{
ImServer *im=new ImServer();
im->InitServer();
im->StartServer();
  return 0;
}
