﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.5483
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

using System.Xml.Serialization;

// 
// This source code was auto-generated by xsd, Version=2.0.50727.1432.
// 


/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true, Namespace="http://www.canadapost.ca/ws/merchant/registration")]
[System.Xml.Serialization.XmlRootAttribute("merchant-info", Namespace="http://www.canadapost.ca/ws/merchant/registration", IsNullable=false)]
public partial class merchantinfo {
    
    private string customernumberField;
    
    private string contractnumberField;
    
    private string merchantusernameField;
    
    private string merchantpasswordField;
    
    private bool hasdefaultcreditcardField;
    
    private bool hasdefaultcreditcardFieldSpecified;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("customer-number")]
    public string customernumber {
        get {
            return this.customernumberField;
        }
        set {
            this.customernumberField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("contract-number")]
    public string contractnumber {
        get {
            return this.contractnumberField;
        }
        set {
            this.contractnumberField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("merchant-username")]
    public string merchantusername {
        get {
            return this.merchantusernameField;
        }
        set {
            this.merchantusernameField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("merchant-password")]
    public string merchantpassword {
        get {
            return this.merchantpasswordField;
        }
        set {
            this.merchantpasswordField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("has-default-credit-card")]
    public bool hasdefaultcreditcard {
        get {
            return this.hasdefaultcreditcardField;
        }
        set {
            this.hasdefaultcreditcardField = value;
        }
    }
    
    /// <remarks/>
    [System.Xml.Serialization.XmlIgnoreAttribute()]
    public bool hasdefaultcreditcardSpecified {
        get {
            return this.hasdefaultcreditcardFieldSpecified;
        }
        set {
            this.hasdefaultcreditcardFieldSpecified = value;
        }
    }
}

/// <remarks/>
[System.CodeDom.Compiler.GeneratedCodeAttribute("xsd", "2.0.50727.1432")]
[System.SerializableAttribute()]
[System.Diagnostics.DebuggerStepThroughAttribute()]
[System.ComponentModel.DesignerCategoryAttribute("code")]
[System.Xml.Serialization.XmlTypeAttribute(AnonymousType=true, Namespace="http://www.canadapost.ca/ws/merchant/registration")]
[System.Xml.Serialization.XmlRootAttribute(Namespace="http://www.canadapost.ca/ws/merchant/registration", IsNullable=false)]
public partial class token {
    
    private string tokenidField;
    
    /// <remarks/>
    [System.Xml.Serialization.XmlElementAttribute("token-id")]
    public string tokenid {
        get {
            return this.tokenidField;
        }
        set {
            this.tokenidField = value;
        }
    }
}