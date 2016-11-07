#!/bin/bash
wget https://github.com/wyolum/alamode/blob/master/bundles/alamode-setup.tar.gz?raw=true -O alamode-setup.tar.gz
tar -xvzf alamode-setup.tar.gz
cd alamode-setup
sudo ./setup
