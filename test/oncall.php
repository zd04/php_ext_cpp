<?php 

var_dump(class_exists("ObjCall123"));

$obj = new ObjCall123();

//$r = $obj->onCall(function(){
//    var_dump(func_get_args());
//});

//使用类的静态方法存储闭包存在内存泄露的风险
$obj->onCall1(function(){
    echo "22222",PHP_EOL;
    var_dump(func_get_args());
    
    echo "2222233333",PHP_EOL;
});

var_dump($obj);


//var_dump($obj->getOnCall(1));

var_dump($obj->getOnCall(1));

$obj_arg = [1,2,3];
//var_dump($obj->callInC($obj_arg));


var_dump($obj->callInC1($obj_arg));