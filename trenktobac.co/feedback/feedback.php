<?php  
  	$headers = "From: trenktobacco@gmail.com\n";
	$headers .= 'Content-type: text/html; charset=utf-8' . "\r\n";
	
	require '../mailer/PHPMailerAutoload.php';

        $mail = new PHPMailer(true);

	$mail->CharSet = "UTF-8";
	$mail->isHTML(true);
	$mail->IsSMTP(); // telling the class to use SMTP
	$mail->SMTPAuth = true; // enable SMTP authentication
	$mail->SMTPSecure = "ssl"; // sets the prefix to the servier
	$mail->Host = "smtp.gmail.com"; // sets GMAIL as the SMTP server
	$mail->Port = 465; // set the SMTP port for the GMAIL server
	$mail->Username = "trenktobacco@gmail.com"; // GMAIL username
	$mail->Password = "gmail password here"; // GMAIL password

	//Typical mail data
	$mail->AddAddress('trenktobacco@gmail.com', 'Online Feedback');
	$mail->SetFrom("trenktobacco@gmail.com", "Trenk Tobacco");
	$mail->Subject = "Online Feedback";
	$mail->Body = $_POST['feedback'];

	try{
	    $mail->Send();
	    echo "Your feedback was received!";
	} catch(Exception $e){
	    //Something went bad
	    echo "Fail - " . $mail->ErrorInfo;
	}
?>