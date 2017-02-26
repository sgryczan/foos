FROM armhf/alpine:latest

RUN mkdir /app
COPY . /app
WORKDIR /app/node/
RUN apk add --no-cache \
    python \
    python-dev \
    py-pip \
    build-base \
    nodejs
RUN pip install pyserial jsonpickle
RUN npm install
EXPOSE 3000
CMD ["node", "foos.js"]
