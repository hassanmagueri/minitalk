server=$(ps | awk '/server/ {print $1; exit}' )
echo $server

$(./client $server "$(cat $1)")
