using namespace Singleton
{
    
    // Version non singleton
    public class Policy{
        // instance 
        public Policy instance {get; set;}
        public Policy(){
            instance = new Policy();
        }
    }

    // Version non thread safe 
    public class Policy {
        public readonly Policy instance {
        get{
            if (instance == null)
                instance = new Policy();
        };
        }

    }

    // version thread safe
    public class Policy {
        pulic readonly object _lock = new object();
        public readonly Policy instance{
            get{
                lock(_lock){
                if (instance == null)
                instance = new Policy();
                            }
                };
        }

    }
    
}