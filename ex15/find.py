from stegano import lsb
from stegano.lsb import generators

secret_message = lsb.reveal("./42.png", generators.eratosthenes())

print("Gizli mesaj:", secret_message)
