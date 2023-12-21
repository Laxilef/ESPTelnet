/////////////////////////////////////////////////////////////////

#include "ESPTelnetStream.h"

/////////////////////////////////////////////////////////////////

void ESPTelnetStream::handleInput() {
  char c = client.read();
  on_input(String(c));
}

/////////////////////////////////////////////////////////////////

int ESPTelnetStream::available() {
  if (client && isConnected()) {
    return client.available();
  } else {
    return 0;
  }
}

/////////////////////////////////////////////////////////////////

int ESPTelnetStream::read() {
  if (client && isConnected()) {
    return client.read();
  } else {
    return 0;
  }
}

/////////////////////////////////////////////////////////////////

int ESPTelnetStream::peek() {
  if (client && isConnected()) {
    return client.peek();
  } else {
    return 0;
  }
}

/////////////////////////////////////////////////////////////////

void ESPTelnetStream::flush() {
  if (client && isConnected()) {
    if (!client.flush(this->getKeepAliveInterval())) {
      this->disconnectClient();
    }
  }
}

/////////////////////////////////////////////////////////////////

size_t ESPTelnetStream::write(uint8_t data) {
  if (client && isConnected()) {
    size_t written = client.write(data);
    if (!written) {
      this->disconnectClient();
    }

    return written;
  } else {
    return 0;
  }
}

/////////////////////////////////////////////////////////////////

size_t ESPTelnetStream::write(const uint8_t* data, size_t size) {
  if (client && isConnected()) {
    size_t written = client.write(data, size);
    if (!written) {
      this->disconnectClient();
    }

    return written;
  } else {
    return 0;
  }
}

/////////////////////////////////////////////////////////////////