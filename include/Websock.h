// Websock.h
#ifndef WEBSOCK_H
#define WEBSOCK_H

#include <cpprest/ws_client.h>
#include <vector>
#include <string>
#include <shared_mutex>

class Websock
{
private:
  web::websockets::client::websocket_callback_client client;
  void message_handler(web::websockets::client::websocket_incoming_message msg);
  void send_message(std::string to_send);
  std::string subscribe(bool sub);
  std::vector<double> buy_prices;
  std::vector<double> sell_prices;
  std::shared_mutex buy_mut, sell_mut;
  std::vector<std::string> Channels;
  std::string Product_id;
  std::string Uri;
  bool is_connected;
public:
  double Best_Buy_Price();
  double Best_Sell_Price();
  double MidMarket_Price();

  void Connect();
  void Disconnect();
  Websock(std::vector<std::string> channels, std::string product_id, std::string uri);
  ~Websock();
};
#endif // WEBSOCK_H
