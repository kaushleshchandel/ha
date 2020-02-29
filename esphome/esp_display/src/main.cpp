// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using namespace text_sensor;
using namespace time;
using namespace switch_;
using namespace display;
logger::Logger *logger_logger;
status_led::StatusLED *status_led_statusled;
wifi::WiFiComponent *wifi_wificomponent;
ota::OTAComponent *myota;
mqtt::MQTTClientComponent *mqtt_mqttclientcomponent;
api::APIServer *api_apiserver;
using namespace sensor;
using namespace mqtt;
using namespace api;
using namespace i2c;
i2c::I2CComponent *i2c_i2ccomponent;
using namespace json;
display::Font *font1;
display::Font *font3;
homeassistant::HomeassistantTextSensor *alarm_state;
rotary_encoder::RotaryEncoderSensor *rencoder;
dht::DHT *dht_dht;
homeassistant::HomeassistantTime *esptime;
gpio::GPIOSwitch *gpio_gpioswitch;
ssd1306_i2c::I2CSSD1306 *my_display;
interval::IntervalTrigger *interval_intervaltrigger;
mqtt::MQTTTextSensor *mqtt_mqtttextsensor;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent;
mqtt::MQTTSwitchComponent *mqtt_mqttswitchcomponent;
Automation<> *automation;
display::DisplayPageShowAction<> *display_displaypageshowaction;
sensor::Sensor *sensor_sensor;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent_2;
display::DisplayPage *page_init;
display::DisplayPage *page_status;
sensor::Sensor *sensor_sensor_2;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent_3;
display::DisplayPage *page_setting;
display::DisplayPage *page_error;
UpdateComponentAction<> *updatecomponentaction;
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  // esphome:
  //   name: esp_display
  //   platform: ESP8266
  //   board: d1_mini
  //   includes: []
  //   arduino_version: espressif8266@2.2.3
  //   libraries: []
  //   platformio_options: {}
  //   esp8266_restore_from_flash: false
  //   board_flash_mode: dout
  //   build_path: esp_display
  App.pre_setup("esp_display", __DATE__ ", " __TIME__);
  // text_sensor:
  // time:
  // switch:
  // display:
  // logger:
  //   id: logger_logger
  //   hardware_uart: UART0
  //   esp8266_store_log_strings_in_flash: true
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   logs: {}
  //   level: DEBUG
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  App.register_component(logger_logger);
  // status_led:
  //   pin:
  //     number: 2
  //     inverted: true
  //     mode: OUTPUT
  //   id: status_led_statusled
  status_led_statusled = new status_led::StatusLED(new GPIOPin(2, OUTPUT, true));
  App.register_component(status_led_statusled);
  status_led_statusled->pre_setup();
  // wifi:
  //   networks:
  //   - ssid: !secret 'WIFI_SSID'
  //     password: !secret 'WIFI_password'
  //     priority: 0.0
  //     id: wifi_wifiap
  //   - ssid: HOME2G
  //     password: !secret 'WIFI_password'
  //     priority: 1.0
  //     id: wifi_wifiap_2
  //   ap:
  //     ssid: esp_display
  //     password: !secret 'AP_password'
  //     id: wifi_wifiap_3
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   power_save_mode: NONE
  //   output_power: 20.0
  //   fast_connect: false
  //   domain: .local
  //   reboot_timeout: 15min
  //   use_address: esp_display.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("esp_display.local");
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("IOT");
  wifi_wifiap.set_password("608980608980");
  wifi_wifiap.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap);
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("HOME2G");
  wifi_wifiap_2.set_password("608980608980");
  wifi_wifiap_2.set_priority(1.0f);
  wifi_wificomponent->add_sta(wifi_wifiap_2);
  wifi::WiFiAP wifi_wifiap_3 = wifi::WiFiAP();
  wifi_wifiap_3.set_ssid("esp_display");
  wifi_wifiap_3.set_password("1234567890");
  wifi_wificomponent->set_ap(wifi_wifiap_3);
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_output_power(20.0f);
  App.register_component(wifi_wificomponent);
  // ota:
  //   safe_mode: true
  //   id: myota
  //   password: ''
  //   port: 8266
  myota = new ota::OTAComponent();
  myota->set_port(8266);
  myota->set_auth_password("");
  App.register_component(myota);
  myota->start_safe_mode();
  // mqtt:
  //   broker: 192.168.0.100
  //   discovery_prefix: homeassistant
  //   password: ''
  //   id: mqtt_mqttclientcomponent
  //   discovery_retain: true
  //   topic_prefix: esp_display
  //   discovery: true
  //   username: ''
  //   keepalive: 15s
  //   reboot_timeout: 15min
  //   port: 1883
  //   birth_message:
  //     topic: esp_display/status
  //     payload: online
  //     qos: 0
  //     retain: true
  //   will_message:
  //     topic: esp_display/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   shutdown_message:
  //     topic: esp_display/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   log_topic:
  //     topic: esp_display/debug
  //     qos: 0
  //     retain: true
  mqtt_mqttclientcomponent = new mqtt::MQTTClientComponent();
  App.register_component(mqtt_mqttclientcomponent);
  // api:
  //   password: ''
  //   id: api_apiserver
  //   reboot_timeout: 15min
  //   port: 6053
  api_apiserver = new api::APIServer();
  App.register_component(api_apiserver);
  // sensor:
  mqtt_mqttclientcomponent->set_broker_address("192.168.0.100");
  mqtt_mqttclientcomponent->set_broker_port(1883);
  mqtt_mqttclientcomponent->set_username("");
  mqtt_mqttclientcomponent->set_password("");
  mqtt_mqttclientcomponent->set_discovery_info("homeassistant", true);
  mqtt_mqttclientcomponent->set_topic_prefix("esp_display");
  mqtt_mqttclientcomponent->set_birth_message(mqtt::MQTTMessage{
      .topic = "esp_display/status",
      .payload = "online",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_last_will(mqtt::MQTTMessage{
      .topic = "esp_display/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_shutdown_message(mqtt::MQTTMessage{
      .topic = "esp_display/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_log_message_template(mqtt::MQTTMessage{
      .topic = "esp_display/debug",
      .payload = "",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_keep_alive(15);
  mqtt_mqttclientcomponent->set_reboot_timeout(900000);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);
  // i2c:
  //   sda: 4
  //   scl: 5
  //   scan: false
  //   frequency: 700000.0
  //   id: i2c_i2ccomponent
  i2c_i2ccomponent = new i2c::I2CComponent();
  App.register_component(i2c_i2ccomponent);
  // json:
  // substitutions:
  //   devicename: esp_display
  //   device_shortname: esp
  // font:
  //   file: slkscr.ttf
  //   id: font1
  //   size: 8
  //   glyphs:
  //   - ' '
  //   - '!'
  //   - '"'
  //   - '%'
  //   - (
  //   - )
  //   - +
  //   - ','
  //   - '-'
  //   - .
  //   - '0'
  //   - '1'
  //   - '2'
  //   - '3'
  //   - '4'
  //   - '5'
  //   - '6'
  //   - '7'
  //   - '8'
  //   - '9'
  //   - ':'
  //   - A
  //   - B
  //   - C
  //   - D
  //   - E
  //   - F
  //   - G
  //   - H
  //   - I
  //   - J
  //   - K
  //   - L
  //   - M
  //   - N
  //   - O
  //   - P
  //   - Q
  //   - R
  //   - S
  //   - T
  //   - U
  //   - V
  //   - W
  //   - X
  //   - Y
  //   - Z
  //   - _
  //   - a
  //   - b
  //   - c
  //   - d
  //   - e
  //   - f
  //   - g
  //   - h
  //   - i
  //   - j
  //   - k
  //   - l
  //   - m
  //   - n
  //   - o
  //   - p
  //   - q
  //   - r
  //   - s
  //   - t
  //   - u
  //   - v
  //   - w
  //   - x
  //   - y
  //   - z
  //   - °
  //   raw_data_id: uint8_t_2
  static const uint8_t uint8_t_2[] PROGMEM = {0x40, 0x40, 0x40, 0x00, 0x40, 0x50, 0x50, 0x00, 0x00, 0x00, 0x68, 0x68, 0x10, 0x2C, 0x2C, 0x20, 0x40, 0x40, 0x40, 0x20, 0x40, 0x20, 0x20, 0x20, 0x40, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x40, 0x80, 0x70, 0x00, 0x00, 0x80, 0x30, 0x48, 0x48, 0x48, 0x30, 0x60, 0x20, 0x20, 0x20, 0x70, 0x70, 0x08, 0x30, 0x40, 0x78, 0x70, 0x08, 0x30, 0x08, 0x70, 0x50, 0x50, 0x50, 0x78, 0x10, 0x78, 0x40, 0x70, 0x08, 0x70, 0x30, 0x40, 0x70, 0x48, 0x30, 0x78, 0x08, 0x10, 0x20, 0x20, 0x30, 0x48, 0x30, 0x48, 0x30, 0x30, 0x48, 0x38, 0x08, 0x30, 0x80, 0x00, 0x80, 0x00, 0x30, 0x48, 0x78, 0x48, 0x48, 0x70, 0x48, 0x70, 0x48, 0x70, 0x30, 0x48, 0x40, 0x48, 0x30, 0x70, 0x48, 0x48, 0x48, 0x70, 0x70, 0x40, 0x70, 0x40, 0x70, 0x70, 0x40, 0x70, 0x40, 0x40, 0x38, 0x40, 0x58, 0x48, 0x30, 0x48, 0x48, 0x78, 0x48, 0x48, 0x40, 0x40, 0x40, 0x40, 0x40, 0x08, 0x08, 0x08, 0x48, 0x30, 0x48, 0x50, 0x60, 0x50, 0x48, 0x40, 0x40, 0x40, 0x40, 0x70, 0x44, 0x6C, 0x54, 0x44, 0x44, 0x44, 0x64, 0x54, 0x4C, 0x44, 0x30, 0x48, 0x48, 0x48, 0x30, 0x70, 0x48, 0x70, 0x40, 0x40, 0x30, 0x48, 0x48, 0x48, 0x30, 0x08, 0x70, 0x48, 0x70, 0x50, 0x48, 0x38, 0x40, 0x30, 0x08, 0x70, 0x70, 0x20, 0x20, 0x20, 0x20, 0x48, 0x48, 0x48, 0x48, 0x30, 0x44, 0x44, 0x28, 0x28, 0x10, 0x44, 0x54, 0x54, 0x54, 0x28, 0x44, 0x28, 0x10, 0x28, 0x44, 0x44, 0x28, 0x10, 0x10, 0x10, 0x70, 0x10, 0x20, 0x40, 0x70, 0x78, 0x30, 0x48, 0x78, 0x48, 0x48, 0x70, 0x48, 0x70, 0x48, 0x70, 0x30, 0x48, 0x40, 0x48, 0x30, 0x70, 0x48, 0x48, 0x48, 0x70, 0x70, 0x40, 0x70, 0x40, 0x70, 0x70, 0x40, 0x70, 0x40, 0x40, 0x38, 0x40, 0x58, 0x48, 0x30, 0x48, 0x48, 0x78, 0x48, 0x48, 0x40, 0x40, 0x40, 0x40, 0x40, 0x08, 0x08, 0x08, 0x48, 0x30, 0x48, 0x50, 0x60, 0x50, 0x48, 0x40, 0x40, 0x40, 0x40, 0x70, 0x44, 0x6C, 0x54, 0x44, 0x44, 0x44, 0x64, 0x54, 0x4C, 0x44, 0x30, 0x48, 0x48, 0x48, 0x30, 0x70, 0x48, 0x70, 0x40, 0x40, 0x30, 0x48, 0x48, 0x48, 0x30, 0x08, 0x70, 0x48, 0x70, 0x50, 0x48, 0x38, 0x40, 0x30, 0x08, 0x70, 0x70, 0x20, 0x20, 0x20, 0x20, 0x48, 0x48, 0x48, 0x48, 0x30, 0x44, 0x44, 0x28, 0x28, 0x10, 0x44, 0x54, 0x54, 0x54, 0x28, 0x44, 0x28, 0x10, 0x28, 0x44, 0x44, 0x28, 0x10, 0x10, 0x10, 0x70, 0x10, 0x20, 0x40, 0x70, 0xF0, 0x90, 0x90, 0x90, 0x90, 0xF0};
  font1 = new display::Font({display::Glyph(" ", uint8_t_2, 0, 0, 7, 4, 0), display::Glyph("!", uint8_t_2, 0, 0, 2, 3, 5), display::Glyph("\042", uint8_t_2, 5, 0, 2, 5, 5), display::Glyph("%", uint8_t_2, 10, 0, 2, 7, 5), display::Glyph("(", uint8_t_2, 15, 0, 2, 4, 5), display::Glyph(")", uint8_t_2, 20, 0, 2, 4, 5), display::Glyph("+", uint8_t_2, 25, 0, 2, 7, 5), display::Glyph(",", uint8_t_2, 30, 0, 6, 3, 2), display::Glyph("-", uint8_t_2, 32, 0, 4, 5, 3), display::Glyph(".", uint8_t_2, 35, 0, 6, 2, 1), display::Glyph("0", uint8_t_2, 36, 0, 2, 6, 5), display::Glyph("1", uint8_t_2, 41, 0, 2, 5, 5), display::Glyph("2", uint8_t_2, 46, 0, 2, 6, 5), display::Glyph("3", uint8_t_2, 51, 0, 2, 6, 5), display::Glyph("4", uint8_t_2, 56, 0, 2, 6, 5), display::Glyph("5", uint8_t_2, 61, 0, 2, 6, 5), display::Glyph("6", uint8_t_2, 66, 0, 2, 6, 5), display::Glyph("7", uint8_t_2, 71, 0, 2, 6, 5), display::Glyph("8", uint8_t_2, 76, 0, 2, 6, 5), display::Glyph("9", uint8_t_2, 81, 0, 2, 6, 5), display::Glyph(":", uint8_t_2, 86, 0, 3, 2, 4), display::Glyph("A", uint8_t_2, 90, 0, 2, 6, 5), display::Glyph("B", uint8_t_2, 95, 0, 2, 6, 5), display::Glyph("C", uint8_t_2, 100, 0, 2, 6, 5), display::Glyph("D", uint8_t_2, 105, 0, 2, 6, 5), display::Glyph("E", uint8_t_2, 110, 0, 2, 5, 5), display::Glyph("F", uint8_t_2, 115, 0, 2, 5, 5), display::Glyph("G", uint8_t_2, 120, 0, 2, 6, 5), display::Glyph("H", uint8_t_2, 125, 0, 2, 6, 5), display::Glyph("I", uint8_t_2, 130, 0, 2, 3, 5), display::Glyph("J", uint8_t_2, 135, 0, 2, 6, 5), display::Glyph("K", uint8_t_2, 140, 0, 2, 6, 5), display::Glyph("L", uint8_t_2, 145, 0, 2, 5, 5), display::Glyph("M", uint8_t_2, 150, 0, 2, 7, 5), display::Glyph("N", uint8_t_2, 155, 0, 2, 7, 5), display::Glyph("O", uint8_t_2, 160, 0, 2, 6, 5), display::Glyph("P", uint8_t_2, 165, 0, 2, 6, 5), display::Glyph("Q", uint8_t_2, 170, 0, 2, 6, 6), display::Glyph("R", uint8_t_2, 176, 0, 2, 6, 5), display::Glyph("S", uint8_t_2, 181, 0, 2, 6, 5), display::Glyph("T", uint8_t_2, 186, 0, 2, 5, 5), display::Glyph("U", uint8_t_2, 191, 0, 2, 6, 5), display::Glyph("V", uint8_t_2, 196, 0, 2, 7, 5), display::Glyph("W", uint8_t_2, 201, 0, 2, 7, 5), display::Glyph("X", uint8_t_2, 206, 0, 2, 7, 5), display::Glyph("Y", uint8_t_2, 211, 0, 2, 7, 5), display::Glyph("Z", uint8_t_2, 216, 0, 2, 5, 5), display::Glyph("_", uint8_t_2, 221, 0, 7, 6, 1), display::Glyph("a", uint8_t_2, 222, 0, 2, 6, 5), display::Glyph("b", uint8_t_2, 227, 0, 2, 6, 5), display::Glyph("c", uint8_t_2, 232, 0, 2, 6, 5), display::Glyph("d", uint8_t_2, 237, 0, 2, 6, 5), display::Glyph("e", uint8_t_2, 242, 0, 2, 5, 5), display::Glyph("f", uint8_t_2, 247, 0, 2, 5, 5), display::Glyph("g", uint8_t_2, 252, 0, 2, 6, 5), display::Glyph("h", uint8_t_2, 257, 0, 2, 6, 5), display::Glyph("i", uint8_t_2, 262, 0, 2, 3, 5), display::Glyph("j", uint8_t_2, 267, 0, 2, 6, 5), display::Glyph("k", uint8_t_2, 272, 0, 2, 6, 5), display::Glyph("l", uint8_t_2, 277, 0, 2, 5, 5), display::Glyph("m", uint8_t_2, 282, 0, 2, 7, 5), display::Glyph("n", uint8_t_2, 287, 0, 2, 7, 5), display::Glyph("o", uint8_t_2, 292, 0, 2, 6, 5), display::Glyph("p", uint8_t_2, 297, 0, 2, 6, 5), display::Glyph("q", uint8_t_2, 302, 0, 2, 6, 6), display::Glyph("r", uint8_t_2, 308, 0, 2, 6, 5), display::Glyph("s", uint8_t_2, 313, 0, 2, 6, 5), display::Glyph("t", uint8_t_2, 318, 0, 2, 5, 5), display::Glyph("u", uint8_t_2, 323, 0, 2, 6, 5), display::Glyph("v", uint8_t_2, 328, 0, 2, 7, 5), display::Glyph("w", uint8_t_2, 333, 0, 2, 7, 5), display::Glyph("x", uint8_t_2, 338, 0, 2, 7, 5), display::Glyph("y", uint8_t_2, 343, 0, 2, 7, 5), display::Glyph("z", uint8_t_2, 348, 0, 2, 5, 5), display::Glyph("\302\260", uint8_t_2, 353, 0, 1, 4, 6)}, 7, 9);
  // font:
  //   file: arial.ttf
  //   id: font3
  //   size: 14
  //   glyphs:
  //   - ' '
  //   - '!'
  //   - '"'
  //   - '%'
  //   - (
  //   - )
  //   - +
  //   - ','
  //   - '-'
  //   - .
  //   - '0'
  //   - '1'
  //   - '2'
  //   - '3'
  //   - '4'
  //   - '5'
  //   - '6'
  //   - '7'
  //   - '8'
  //   - '9'
  //   - ':'
  //   - A
  //   - B
  //   - C
  //   - D
  //   - E
  //   - F
  //   - G
  //   - H
  //   - I
  //   - J
  //   - K
  //   - L
  //   - M
  //   - N
  //   - O
  //   - P
  //   - Q
  //   - R
  //   - S
  //   - T
  //   - U
  //   - V
  //   - W
  //   - X
  //   - Y
  //   - Z
  //   - _
  //   - a
  //   - b
  //   - c
  //   - d
  //   - e
  //   - f
  //   - g
  //   - h
  //   - i
  //   - j
  //   - k
  //   - l
  //   - m
  //   - n
  //   - o
  //   - p
  //   - q
  //   - r
  //   - s
  //   - t
  //   - u
  //   - v
  //   - w
  //   - x
  //   - y
  //   - z
  //   - °
  //   raw_data_id: uint8_t_3
  static const uint8_t uint8_t_3[] PROGMEM = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x20, 0x50, 0x50, 0x50, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x80, 0x49, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x32, 0x00, 0x04, 0xC0, 0x05, 0x20, 0x09, 0x20, 0x09, 0x20, 0x10, 0xC0, 0x10, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x10, 0x40, 0x20, 0x20, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x40, 0x08, 0x08, 0x08, 0x7F, 0x08, 0x08, 0x08, 0x00, 0x20, 0x20, 0x20, 0xF0, 0x00, 0x00, 0x00, 0x20, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x08, 0x18, 0x28, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x3C, 0x42, 0x42, 0x02, 0x02, 0x04, 0x08, 0x10, 0x20, 0x7E, 0x3C, 0x42, 0x42, 0x02, 0x1C, 0x02, 0x02, 0x42, 0x42, 0x3C, 0x04, 0x0C, 0x14, 0x24, 0x24, 0x44, 0x84, 0xFE, 0x04, 0x04, 0x3E, 0x20, 0x40, 0x7C, 0x42, 0x02, 0x02, 0x42, 0x44, 0x3C, 0x1C, 0x22, 0x40, 0x40, 0x5C, 0x62, 0x42, 0x42, 0x42, 0x3C, 0x7E, 0x02, 0x04, 0x04, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x3C, 0x42, 0x42, 0x42, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x3C, 0x42, 0x42, 0x42, 0x46, 0x3A, 0x02, 0x02, 0x44, 0x38, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x04, 0x00, 0x0A, 0x00, 0x0A, 0x00, 0x0A, 0x00, 0x11, 0x00, 0x11, 0x00, 0x3F, 0x80, 0x20, 0x80, 0x40, 0x40, 0x40, 0x40, 0x7E, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x7E, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x7E, 0x00, 0x1E, 0x00, 0x21, 0x00, 0x40, 0x80, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x80, 0x21, 0x00, 0x1E, 0x00, 0x7E, 0x00, 0x41, 0x00, 0x40, 0x80, 0x40, 0x80, 0x40, 0x80, 0x40, 0x80, 0x40, 0x80, 0x40, 0x80, 0x41, 0x00, 0x7E, 0x00, 0x7F, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x7F, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x7F, 0x00, 0x7F, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x7E, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x1F, 0x00, 0x20, 0x80, 0x40, 0x40, 0x40, 0x00, 0x40, 0x00, 0x43, 0xC0, 0x40, 0x40, 0x40, 0x40, 0x20, 0x80, 0x1F, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x7F, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x44, 0x44, 0x38, 0x40, 0x80, 0x41, 0x00, 0x42, 0x00, 0x44, 0x00, 0x48, 0x00, 0x54, 0x00, 0x62, 0x00, 0x42, 0x00, 0x41, 0x00, 0x40, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7F, 0x40, 0x40, 0x60, 0xC0, 0x60, 0xC0, 0x51, 0x40, 0x51, 0x40, 0x4A, 0x40, 0x4A, 0x40, 0x4A, 0x40, 0x44, 0x40, 0x44, 0x40, 0x41, 0x00, 0x61, 0x00, 0x51, 0x00, 0x51, 0x00, 0x49, 0x00, 0x49, 0x00, 0x45, 0x00, 0x45, 0x00, 0x43, 0x00, 0x41, 0x00, 0x1F, 0x00, 0x20, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x80, 0x1F, 0x00, 0x7E, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x7E, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x1F, 0x00, 0x20, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x42, 0x80, 0x21, 0x80, 0x1E, 0xC0, 0x00, 0x00, 0x7F, 0x00, 0x40, 0x80, 0x40, 0x80, 0x40, 0x80, 0x40, 0x80, 0x7F, 0x00, 0x44, 0x00, 0x42, 0x00, 0x41, 0x00, 0x40, 0x80, 0x3E, 0x00, 0x41, 0x00, 0x41, 0x00, 0x40, 0x00, 0x38, 0x00, 0x07, 0x00, 0x01, 0x00, 0x41, 0x00, 0x41, 0x00, 0x3E, 0x00, 0x7F, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x22, 0x00, 0x1C, 0x00, 0x40, 0x40, 0x40, 0x40, 0x20, 0x80, 0x20, 0x80, 0x11, 0x00, 0x11, 0x00, 0x0A, 0x00, 0x0A, 0x00, 0x04, 0x00, 0x04, 0x00, 0x82, 0x08, 0x85, 0x08, 0x45, 0x10, 0x45, 0x10, 0x45, 0x10, 0x28, 0xA0, 0x28, 0xA0, 0x28, 0xA0, 0x10, 0x40, 0x10, 0x40, 0x81, 0x00, 0x42, 0x00, 0x42, 0x00, 0x24, 0x00, 0x18, 0x00, 0x18, 0x00, 0x24, 0x00, 0x42, 0x00, 0x42, 0x00, 0x81, 0x00, 0x80, 0x80, 0x41, 0x00, 0x22, 0x00, 0x22, 0x00, 0x14, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x7F, 0x00, 0x02, 0x00, 0x04, 0x00, 0x04, 0x00, 0x08, 0x00, 0x10, 0x00, 0x20, 0x00, 0x20, 0x00, 0x40, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x3C, 0x42, 0x02, 0x1E, 0x22, 0x42, 0x46, 0x3A, 0x40, 0x40, 0x5C, 0x62, 0x42, 0x42, 0x42, 0x42, 0x62, 0x5C, 0x38, 0x44, 0x40, 0x40, 0x40, 0x40, 0x44, 0x38, 0x02, 0x02, 0x3A, 0x46, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3A, 0x3C, 0x42, 0x42, 0x7E, 0x40, 0x40, 0x42, 0x3C, 0x30, 0x40, 0xF0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x3A, 0x46, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3A, 0x02, 0x42, 0x3C, 0x40, 0x40, 0x5C, 0x62, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x40, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x20, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xC0, 0x40, 0x40, 0x42, 0x44, 0x48, 0x50, 0x68, 0x44, 0x44, 0x42, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x5B, 0x80, 0x66, 0x40, 0x44, 0x40, 0x44, 0x40, 0x44, 0x40, 0x44, 0x40, 0x44, 0x40, 0x44, 0x40, 0x5C, 0x62, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C, 0x5C, 0x62, 0x42, 0x42, 0x42, 0x42, 0x62, 0x5C, 0x40, 0x40, 0x40, 0x3A, 0x46, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3A, 0x02, 0x02, 0x02, 0x58, 0x60, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x38, 0x44, 0x40, 0x38, 0x04, 0x04, 0x44, 0x38, 0x00, 0x40, 0x40, 0xF0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x70, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x46, 0x3A, 0x40, 0x40, 0x22, 0x22, 0x14, 0x14, 0x08, 0x08, 0x88, 0x80, 0x88, 0x80, 0x55, 0x00, 0x55, 0x00, 0x55, 0x00, 0x55, 0x00, 0x22, 0x00, 0x22, 0x00, 0x84, 0x48, 0x48, 0x30, 0x30, 0x48, 0x48, 0x84, 0x40, 0x40, 0x22, 0x22, 0x14, 0x14, 0x14, 0x08, 0x08, 0x08, 0x30, 0xFC, 0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0xFC, 0x30, 0x48, 0x48, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  font3 = new display::Font({display::Glyph(" ", uint8_t_3, 0, 0, 13, 4, 0), display::Glyph("!", uint8_t_3, 0, 0, 3, 4, 10), display::Glyph("\042", uint8_t_3, 10, 0, 3, 5, 10), display::Glyph("%", uint8_t_3, 20, 0, 3, 12, 10), display::Glyph("(", uint8_t_3, 40, 0, 3, 5, 13), display::Glyph(")", uint8_t_3, 53, 0, 3, 5, 13), display::Glyph("+", uint8_t_3, 66, 0, 5, 8, 8), display::Glyph(",", uint8_t_3, 74, 0, 12, 4, 3), display::Glyph("-", uint8_t_3, 77, 0, 9, 5, 4), display::Glyph(".", uint8_t_3, 81, 0, 12, 4, 1), display::Glyph("0", uint8_t_3, 82, 0, 3, 8, 10), display::Glyph("1", uint8_t_3, 92, 0, 3, 8, 10), display::Glyph("2", uint8_t_3, 102, 0, 3, 8, 10), display::Glyph("3", uint8_t_3, 112, 0, 3, 8, 10), display::Glyph("4", uint8_t_3, 122, 0, 3, 8, 10), display::Glyph("5", uint8_t_3, 132, 0, 3, 8, 10), display::Glyph("6", uint8_t_3, 142, 0, 3, 8, 10), display::Glyph("7", uint8_t_3, 152, 0, 3, 8, 10), display::Glyph("8", uint8_t_3, 162, 0, 3, 8, 10), display::Glyph("9", uint8_t_3, 172, 0, 3, 8, 10), display::Glyph(":", uint8_t_3, 182, 0, 5, 4, 8), display::Glyph("A", uint8_t_3, 190, -1, 3, 12, 10), display::Glyph("B", uint8_t_3, 210, 0, 3, 9, 10), display::Glyph("C", uint8_t_3, 230, 0, 3, 10, 10), display::Glyph("D", uint8_t_3, 250, 0, 3, 10, 10), display::Glyph("E", uint8_t_3, 270, 0, 3, 9, 10), display::Glyph("F", uint8_t_3, 290, 0, 3, 9, 10), display::Glyph("G", uint8_t_3, 310, 0, 3, 11, 10), display::Glyph("H", uint8_t_3, 330, 0, 3, 10, 10), display::Glyph("I", uint8_t_3, 350, 0, 3, 4, 10), display::Glyph("J", uint8_t_3, 360, 0, 3, 7, 10), display::Glyph("K", uint8_t_3, 370, 0, 3, 10, 10), display::Glyph("L", uint8_t_3, 390, 0, 3, 8, 10), display::Glyph("M", uint8_t_3, 400, 0, 3, 12, 10), display::Glyph("N", uint8_t_3, 420, 0, 3, 10, 10), display::Glyph("O", uint8_t_3, 440, 0, 3, 11, 10), display::Glyph("P", uint8_t_3, 460, 0, 3, 9, 10), display::Glyph("Q", uint8_t_3, 480, 0, 3, 11, 11), display::Glyph("R", uint8_t_3, 502, 0, 3, 10, 10), display::Glyph("S", uint8_t_3, 522, 0, 3, 9, 10), display::Glyph("T", uint8_t_3, 542, 0, 3, 9, 10), display::Glyph("U", uint8_t_3, 562, 0, 3, 10, 10), display::Glyph("V", uint8_t_3, 582, 0, 3, 10, 10), display::Glyph("W", uint8_t_3, 602, 0, 3, 14, 10), display::Glyph("X", uint8_t_3, 622, 0, 3, 10, 10), display::Glyph("Y", uint8_t_3, 642, 0, 3, 10, 10), display::Glyph("Z", uint8_t_3, 662, 0, 3, 9, 10), display::Glyph("_", uint8_t_3, 682, -1, 13, 10, 3), display::Glyph("a", uint8_t_3, 688, 0, 5, 8, 8), display::Glyph("b", uint8_t_3, 696, 0, 3, 8, 10), display::Glyph("c", uint8_t_3, 706, 0, 5, 7, 8), display::Glyph("d", uint8_t_3, 714, 0, 3, 8, 10), display::Glyph("e", uint8_t_3, 724, 0, 5, 8, 8), display::Glyph("f", uint8_t_3, 732, 0, 3, 5, 10), display::Glyph("g", uint8_t_3, 742, 0, 5, 8, 11), display::Glyph("h", uint8_t_3, 753, 0, 3, 8, 10), display::Glyph("i", uint8_t_3, 763, 0, 3, 3, 10), display::Glyph("j", uint8_t_3, 773, -1, 3, 5, 13), display::Glyph("k", uint8_t_3, 786, 0, 3, 7, 10), display::Glyph("l", uint8_t_3, 796, 0, 3, 3, 10), display::Glyph("m", uint8_t_3, 806, 0, 5, 12, 8), display::Glyph("n", uint8_t_3, 822, 0, 5, 8, 8), display::Glyph("o", uint8_t_3, 830, 0, 5, 8, 8), display::Glyph("p", uint8_t_3, 838, 0, 5, 8, 11), display::Glyph("q", uint8_t_3, 849, 0, 5, 8, 11), display::Glyph("r", uint8_t_3, 860, 0, 5, 5, 8), display::Glyph("s", uint8_t_3, 868, 0, 5, 7, 8), display::Glyph("t", uint8_t_3, 876, 0, 2, 4, 11), display::Glyph("u", uint8_t_3, 887, 0, 5, 8, 8), display::Glyph("v", uint8_t_3, 895, 0, 5, 7, 8), display::Glyph("w", uint8_t_3, 903, 0, 5, 10, 8), display::Glyph("x", uint8_t_3, 919, 0, 5, 7, 8), display::Glyph("y", uint8_t_3, 927, 0, 5, 7, 11), display::Glyph("z", uint8_t_3, 938, 0, 5, 7, 8), display::Glyph("\302\260", uint8_t_3, 946, 0, 3, 6, 10)}, 13, 16);
  // text_sensor.homeassistant:
  //   platform: homeassistant
  //   entity_id: alarm_control_panel.my_alarm_system
  //   name: Alarm State
  //   id: alarm_state
  //   mqtt_id: mqtt_mqtttextsensor
  alarm_state = new homeassistant::HomeassistantTextSensor();
  App.register_component(alarm_state);
  // sensor.rotary_encoder:
  //   platform: rotary_encoder
  //   name: Rotary Encoder
  //   pin_a:
  //     number: 14
  //     mode: INPUT
  //     inverted: false
  //   pin_b:
  //     number: 12
  //     mode: INPUT
  //     inverted: false
  //   min_value: 10
  //   max_value: 50
  //   id: rencoder
  //   mqtt_id: mqtt_mqttsensorcomponent
  //   icon: mdi:rotate-right
  //   force_update: false
  //   resolution: 1
  //   unit_of_measurement: steps
  //   accuracy_decimals: 0
  rencoder = new rotary_encoder::RotaryEncoderSensor();
  App.register_component(rencoder);
  // sensor.dht:
  //   platform: dht
  //   pin:
  //     number: 15
  //     mode: INPUT
  //     inverted: false
  //   temperature:
  //     name: Loft Temperature
  //     mqtt_id: mqtt_mqttsensorcomponent_2
  //     id: sensor_sensor
  //     icon: mdi:thermometer
  //     accuracy_decimals: 1
  //     force_update: false
  //     unit_of_measurement: °C
  //   humidity:
  //     name: Loft Humidity
  //     mqtt_id: mqtt_mqttsensorcomponent_3
  //     id: sensor_sensor_2
  //     icon: mdi:water-percent
  //     accuracy_decimals: 0
  //     force_update: false
  //     unit_of_measurement: '%'
  //   update_interval: 60s
  //   id: dht_dht
  //   model: AUTO_DETECT
  dht_dht = new dht::DHT();
  dht_dht->set_update_interval(60000);
  App.register_component(dht_dht);
  // time.homeassistant:
  //   platform: homeassistant
  //   id: esptime
  //   timezone: CST6CDT5,M3.2.0/2,M11.1.0/2
  esptime = new homeassistant::HomeassistantTime();
  esptime->set_timezone("CST6CDT5,M3.2.0/2,M11.1.0/2");
  // switch.gpio:
  //   platform: gpio
  //   pin:
  //     number: 13
  //     mode: OUTPUT
  //     inverted: false
  //   name: Rotary Switch
  //   mqtt_id: mqtt_mqttswitchcomponent
  //   id: gpio_gpioswitch
  //   restore_mode: RESTORE_DEFAULT_OFF
  //   interlock_wait_time: 0ms
  gpio_gpioswitch = new gpio::GPIOSwitch();
  App.register_component(gpio_gpioswitch);
  // display.ssd1306_i2c:
  //   platform: ssd1306_i2c
  //   model: SH1106_128X32
  //   address: 0x3C
  //   id: my_display
  //   brightness: 0.5
  //   pages:
  //   - id: page_init
  //     lambda: !lambda |-
  //       it.print(0, 10, id(font1), "Welcome!");
  //   - id: page_status
  //     lambda: !lambda |-
  //       it.printf(64, 0, id(font1), TextAlign::TOP_CENTER, "Humidity : %.1f", id(rencoder).state.c_str());
  //   - id: page_setting
  //     lambda: !lambda |-
  //       it.printf(64, 0, id(font1), TextAlign::TOP_CENTER, "Alarm State: %s", id(alarm_state).state.c_str());
  //   - id: page_error
  //     lambda: !lambda |-
  //       it.printf(64, 0, id(font1), TextAlign::TOP_CENTER, "Error");
  //   i2c_id: i2c_i2ccomponent
  //   update_interval: 1s
  my_display = new ssd1306_i2c::I2CSSD1306();
  my_display->set_update_interval(1000);
  App.register_component(my_display);
  // interval:
  //   - interval: 5s
  //     then:
  //     - display.page.show:
  //         id: page_status
  //       type_id: display_displaypageshowaction
  //     - component.update:
  //         id: my_display
  //       type_id: updatecomponentaction
  //     trigger_id: trigger
  //     id: interval_intervaltrigger
  //     automation_id: automation
  interval_intervaltrigger = new interval::IntervalTrigger();
  App.register_component(interval_intervaltrigger);
  i2c_i2ccomponent->set_sda_pin(4);
  i2c_i2ccomponent->set_scl_pin(5);
  i2c_i2ccomponent->set_frequency(700000);
  i2c_i2ccomponent->set_scan(false);
  App.register_text_sensor(alarm_state);
  alarm_state->set_name("Alarm State");
  mqtt_mqtttextsensor = new mqtt::MQTTTextSensor(alarm_state);
  App.register_component(mqtt_mqtttextsensor);
  App.register_sensor(rencoder);
  rencoder->set_name("Rotary Encoder");
  rencoder->set_unit_of_measurement("steps");
  rencoder->set_icon("mdi:rotate-right");
  rencoder->set_accuracy_decimals(0);
  rencoder->set_force_update(false);
  mqtt_mqttsensorcomponent = new mqtt::MQTTSensorComponent(rencoder);
  App.register_component(mqtt_mqttsensorcomponent);
  App.register_component(esptime);
  App.register_switch(gpio_gpioswitch);
  gpio_gpioswitch->set_name("Rotary Switch");
  mqtt_mqttswitchcomponent = new mqtt::MQTTSwitchComponent(gpio_gpioswitch);
  App.register_component(mqtt_mqttswitchcomponent);
  automation = new Automation<>(interval_intervaltrigger);
  display_displaypageshowaction = new display::DisplayPageShowAction<>();
  dht_dht->set_pin(new GPIOPin(15, INPUT, false));
  sensor_sensor = new sensor::Sensor();
  App.register_sensor(sensor_sensor);
  sensor_sensor->set_name("Loft Temperature");
  sensor_sensor->set_unit_of_measurement("\302\260C");
  sensor_sensor->set_icon("mdi:thermometer");
  sensor_sensor->set_accuracy_decimals(1);
  sensor_sensor->set_force_update(false);
  mqtt_mqttsensorcomponent_2 = new mqtt::MQTTSensorComponent(sensor_sensor);
  App.register_component(mqtt_mqttsensorcomponent_2);
  page_init = new display::DisplayPage([=](display::DisplayBuffer & it) -> void {
      it.print(0, 10, font1, "Welcome!");
  });
  alarm_state->set_entity_id("alarm_control_panel.my_alarm_system");
  rencoder->set_pin_a(new GPIOPin(14, INPUT, false));
  gpio_gpioswitch->set_pin(new GPIOPin(13, OUTPUT, false));
  gpio_gpioswitch->set_restore_mode(gpio::GPIO_SWITCH_RESTORE_DEFAULT_OFF);
  page_status = new display::DisplayPage([=](display::DisplayBuffer & it) -> void {
      it.printf(64, 0, font1, TextAlign::TOP_CENTER, "Humidity : %.1f", rencoder->state.c_str());
  });
  rencoder->set_pin_b(new GPIOPin(12, INPUT, false));
  rencoder->set_resolution(rotary_encoder::ROTARY_ENCODER_1_PULSE_PER_CYCLE);
  rencoder->set_min_value(10);
  rencoder->set_max_value(50);
  dht_dht->set_temperature_sensor(sensor_sensor);
  sensor_sensor_2 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_2);
  sensor_sensor_2->set_name("Loft Humidity");
  sensor_sensor_2->set_unit_of_measurement("%");
  sensor_sensor_2->set_icon("mdi:water-percent");
  sensor_sensor_2->set_accuracy_decimals(0);
  sensor_sensor_2->set_force_update(false);
  mqtt_mqttsensorcomponent_3 = new mqtt::MQTTSensorComponent(sensor_sensor_2);
  App.register_component(mqtt_mqttsensorcomponent_3);
  display_displaypageshowaction->set_page(page_status);
  page_setting = new display::DisplayPage([=](display::DisplayBuffer & it) -> void {
      it.printf(64, 0, font1, TextAlign::TOP_CENTER, "Alarm State: %s", alarm_state->state.c_str());
  });
  page_error = new display::DisplayPage([=](display::DisplayBuffer & it) -> void {
      it.printf(64, 0, font1, TextAlign::TOP_CENTER, "Error");
  });
  my_display->set_pages({page_init, page_status, page_setting, page_error});
  dht_dht->set_humidity_sensor(sensor_sensor_2);
  dht_dht->set_dht_model(dht::DHT_MODEL_AUTO_DETECT);
  my_display->set_model(ssd1306_base::SH1106_MODEL_128_32);
  my_display->set_brightness(0.5f);
  updatecomponentaction = new UpdateComponentAction<>(my_display);
  my_display->set_i2c_parent(i2c_i2ccomponent);
  my_display->set_i2c_address(0x3C);
  automation->add_actions({display_displaypageshowaction, updatecomponentaction});
  interval_intervaltrigger->set_update_interval(5000);
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
}
