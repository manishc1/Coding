public class HashSet<E>
extends AbstractSet<E>
implements Set<E>, Cloneable, java.io.Serializable

{
    private transient HashMap<E,Object> map;
    
    // Dummy value to associate with an Object in the backing Map
    
    private static final Object PRESENT = new Object();
    
    
    
    public HashSet() {
        map = new HashMap<>();
    }
    
    // SOME CODE ,i.e Other methods in Hash Set
    
    
    public boolean add(E e) {
        return map.put(e, PRESENT)==null;
    }
    
    
    
    // SOME CODE ,i.e Other methods in Hash Set
}
