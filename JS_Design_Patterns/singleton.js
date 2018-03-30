(function ($) {
    $.CreateSingleton = function (p) {
        var Singleton = {
            config: {
                isPostBack: false,
                async: false,
                cache: false,
                type: 'POST',
                contentType: "application/json; charset=utf-8",
                data: { data: '' },
                dataType: 'json',
                baseURL: "Web Service url",
                method: "",
                ajaxCallMode: 0,
                successMethod: "",
                failureMethod: ""
            },
            init: function () {
                
                
            },
            
            ajaxCall: function () {
                $.ajax({
                    type: Singleton.config.type,
                    contentType: Singleton.config.contentType,
                    cache: Singleton.config.cache,
                    url: Singleton.config.baseURL + Singleton.config.method,
                    data: Singleton.config.data,
                    dataType: Singleton.config.dataType,
                    success: Singleton.config.successMethod,
                    error: Singleton.config.failureMethod,
                    async: Singleton.config.async
                });
            },

            invokeAjax: function(){
                cat.config.method = "method";
                cat.config.data = JSON.stringify({
                    param1: value1
                });
                cat.config.successMethod = cat.invokeAjaxSuccess;
                cat.config.failureMethod = cat.invokeAjaxFailure;
                cat.ajaxCall(cat.config);
            },

            invokeAjaxSuccess: function(data){
            	console.log(data.d);
            },

            invokeAjaxFailure: function(){
            	console.log("Something went wrong.", "error");
            }
        };
        Singleton.init();
    };
    $.fn.CallSingleton = function (p) {
        $.CreateSingleton(p);
    };
})(jQuery);