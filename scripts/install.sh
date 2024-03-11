#!/bin/bash

# Aktualisiere die Paketlisten
sudo apt-get update

# Installiere Nginx (ersetze 'nginx' mit 'nginx=specific_version', wenn nötig)
sudo apt-get install -y nginx

# Installiere Abhängigkeiten für Libcamera (Beispiel für eine generische Installation)
sudo apt-get install -y libcamera-dev

# Installiere Python3 und pip, falls noch nicht vorhanden
sudo apt-get install -y python3 python3-pip

# Upgrade pip
pip3 install --upgrade pip

# Installiere Python-Abhängigkeiten aus requirements.txt
pip3 install -r requirements.txt

# Arduino CLI installieren
cd /tmp
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

# Füge den Arduino CLI binären Pfad zur Umgebungsvariablen PATH hinzu
export PATH=$PATH:/home/pi/bin

# Verifiziere die Installation
arduino-cli version

# Nachbearbeitung oder zusätzliche Konfigurationen hier hinzufügen

echo "Installation abgeschlossen."
