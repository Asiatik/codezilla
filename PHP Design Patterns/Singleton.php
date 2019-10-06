<?php

class SingletonClass {

	//static instance of SingletonClass
    private $instance;
    
	//unreachable constructor
	private function __construct() {
    }

	//access method to static instance of SingletonClass
	public static function getInstance(){
	    if($instance == null){
                $instance = new SingletonClass();
            }
            return $instance;
	}
}