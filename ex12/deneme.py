import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText

# Giriş bilgileri ve e-posta ayarları
smtp_server = 'smtp.gmail.com'
smtp_port = 587
email_address = 'cantosun45@gmail.com'
email_password = 'Vituoz321canodis+'
to_email = 'canodis45@gmail.com'

# E-posta içeriği
subject = 'deneme'
body = 'Merhaba, bu bir test e-postasıdır.'

# MIME mesajı oluşturma
message = MIMEMultipart()
message['From'] = email_address
message['To'] = to_email
message['Subject'] = subject
message.attach(MIMEText(body, 'plain'))

# SMTP sunucusuna bağlanma ve e-postayı gönderme
try:
    server = smtplib.SMTP(smtp_server, smtp_port)
    server.starttls()
    server.login(email_address, email_password)
    text = message.as_string()
    server.sendmail(email_address, to_email, text)
    server.quit()
    print('E-posta başarıyla gönderildi.')
except Exception as e:
    print(f'E-posta gönderilirken hata oluştu: {e}')
