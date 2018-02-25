var canadaPostData = { baseUrl: "http://ws1.postescanada-canadapost.ca/AddressComplete/Interactive/AutoComplete/v1.00/json3.ws?",
    Key: "TP51-UX14-GK79-WT69", SearchTerm: "", Location: "", LocationAccuracy: "2", Country: "CA", LanguagePreference: "EN", MaxSuggestions: "5", MaxResults: "5"
};
var res = "";
onload = function () {

    var eventListener = document.getElementById("HomeAddress");
    eventListener.oninput = callCanadaPost;
};


var callCanadaPost = function (incomingString) {
    
    canadaPostData.SearchTerm = $("#HomeAddress").val();
    console.log(canadaPostData.SearchTerm.toString());
    var url = canadaPostData.baseUrl
        + "&Key=" + canadaPostData.Key
        + "&SearchTerm=" + canadaPostData.SearchTerm
        + "&Location=" + canadaPostData.Location
        + "&LocationAccuracy="+canadaPostData.LocationAccuracy
        + "&Country=" + canadaPostData.Country
        + "&LanguagePreference="+canadaPostData.LanguagePreference;

    console.log(url);
    getData(url);
};

var errorHandler = function (data) { console.log(data) }
var handleData = function (data) {
   
    var dataModel = data.Items;
   // console.log(dataModel);
    for (var i = 0; i < dataModel.length ; i++)
        
        console.log(dataModel[i].Text + "," + dataModel[i].Description);
}


function getData(incoming) {
  
    $.ajax({
        url: incoming,
            //&Key=TP51-UX14-GK79-WT69&SearchTerm=2&Location=&LocationAccuracy=12&Country=CA&LanguagePreference=EN",
        type: 'GET',
        dataType: 'json',
        success: handleData,
        error:errorHandler
    })
}


function AddressComplete_Interactive_Find_v2_10Begin(){
   // function AddressComplete_Interactive_Find_v2_10(Key, SearchTerm, LastId, SearchFor, Country, LanguagePreference, MaxSuggestions, MaxResults) {
        $.getJSON("http://ws1.postescanada-canadapost.ca/AddressComplete/Interactive/Find/v2.10/json3.ws?callback=?",
        {
            Key: canadaPostData.Key,
            SearchTerm: canadaPostData.SearchTerm,
            LastId: canadaPostData.LastId,
            SearchFor: canadaPostData.SearchFor,
            Country: canadaPostData.Country,
            LanguagePreference: canadaPostData.LanguagePreference,
            MaxSuggestions: canadaPostData.MaxSuggestions,
            MaxResults: canadaPostData.MaxResults
        },
        function (data) {
            // Test for an error
            if (data.Items.length == 1 && typeof (data.Items[0].Error) != "undefined") {
                // Show the error message
                alert(data.Items[0].Description);
            }
            else {
                // Check if there were any items found
                if (data.Items.length == 0)
                    alert("Sorry, there were no results");
                else {
                    debugger;
                    console.log(data);
                    // PUT YOUR CODE HERE
                    //FYI: The output is a JS object (e.g. data.Items[0].Id), the keys being:
                    //Id
                    //Text
                    //Highlight
                    //Cursor
                    //Description
                    //Next
                }
            }
        });
    }
//}

function AddressComplete_Interactive_Find_v2_10End(response) {
    console.log(response);
    res = response;
    // Test for an error
    if (response.Items.length == 1 && typeof (response.Items[0].Error) != "undefined") {
        // Show the error message
        console.log(response.Items[0].Description);
    }
    else {
        // Check if there were any items found
        if (response.Items.length == 0)
            console.log("Sorry, there were no results");
        else {
            console.log(response);
            // PUT YOUR CODE HERE
            //FYI: The output is an array of key value pairs (e.g. response.Items[0].Id), the keys being:
            //Id
            //Text
            //Highlight
            //Cursor
            //Description
            //Next
        }
    }
}