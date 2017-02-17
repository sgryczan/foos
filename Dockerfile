FROM armhf/alpine:latest

RUN apk add --no-cache \
    python \
    python-dev \
    py-pip \
    build-base \
    nodejs
RUN pip install pyserial jsonpickle
RUN npm install
RUN mkdir /app
COPY . /app
WORKDIR /app/node/
CMD ["node", "test.js"]
