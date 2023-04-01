print "Enter a string: ";
my $string = <STDIN>;
chomp $string;

if ($string == reverse $string) {
    print "The string is a palindrome!\n";
}
else {
    print "The string is not a palindrome.\n";
}