#include "Websock.h"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
  std::vector<std::string> channels = {"heartbeat", "level2"};
  std::string product_id = "BTC-USD";
  std::string uri = "wss://ws-feed.pro.coinbase.com";
  Websock sock(channels, product_id, uri);
  sock.Connect();
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << "Buy: " << sock.Best_Buy_Price() << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << "Sell: " << sock.Best_Sell_Price() << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::cout << "MidMarket: " << sock.MidMarket_Price() << std::endl;
  sock.Disconnect();
  return 0;
}
