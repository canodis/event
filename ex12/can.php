<?php

include 'class.phpmailer.php';

$mail = new PHPMailer();

$mail->IsSMTP();

$mail->SMTPAuth = true;

$mail->Host = 'smtp.gmail.com';

$mail->Port = 587;

$mail->SMTPSecure = 'tls';

$mail->Username = 'cantosun45@gmail.com';

$mail->Password = 'ppmaubtisgzuszpj';

$mail->SetFrom($mail->Username, 'can tosun');

$mail->AddAddress('canodis45@gmail.com', 'Can Tosun');

$mail->CharSet = 'UTF-8';

$mail->Subject = 'Baslik';

$mail->MsgHTML('Olmuyo aq!');

if($mail->Send()) {

    echo 'Mail gönderildi!';

} else {

    echo 'Mail gönderilirken bir hata oluştu: ' . $mail->ErrorInfo;

}

?>