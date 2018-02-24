var canadaPostData = { Key: "TP51-UX14-GK79-WT69", SearchTerm: "", LastId: "", SearchFor: "Eveything", Country: "CA", LanguagePreference: "EN", MaxSuggestions: "5", MaxResults: "5" };
var res = "";
onload = function () {

    var eventListener = document.getElementById("HomeAddress");
    eventListener.oninput = callCanadaPost;
};


var callCanadaPost = function (incomingString) {
    
    canadaPostData.SearchTerm = $("#HomeAddress").val();
    console.log(canadaPostData.SearchFor.toString());
    AddressComplete_Interactive_Find_v2_10Begin();
};

function AddressComplete_Interactive_Find_v2_10Begin(){
    var script = document.createElement("script"),
        head = document.getElementsByTagName("head")[0],
        url = "http://ws1.postescanada-canadapost.ca/AddressComplete/Interactive/Find/v2.10/json3.ws?";

    // Build the query string
    url += "&Key=" + encodeURIComponent(canadaPostData.Key);
    url += "&SearchTerm=" + encodeURIComponent(canadaPostData.SearchTerm);
    url += "&LastId=" + encodeURIComponent(canadaPostData.LastId);
    url += "&SearchFor=" + encodeURIComponent(canadaPostData.SearchFor);
    url += "&Country=" + encodeURIComponent(canadaPostData.Country);
    url += "&LanguagePreference=" + encodeURIComponent(canadaPostData.LanguagePreference);
    url += "&MaxSuggestions=" + encodeURIComponent(canadaPostData.MaxSuggestions);
    url += "&MaxResults=" + encodeURIComponent(canadaPostData.MaxResults);
    url += "&callback=AddressComplete_Interactive_Find_v2_10End";

    script.src = url;
    console.log(url);
    // Make the request
    script.onload = script.onreadystatechange = function () {
        if (!this.readyState || this.readyState === "loaded" || this.readyState === "complete") {
            script.onload = script.onreadystatechange = null;
            if (head && script.parentNode)
                head.removeChild(script);
        }
    }

    head.insertBefore(script, head.firstChild);
}

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